#include "main.h"
/* ===================== NOVAS FUNÇÕES ===================== */

// 1) Injetar chaves
int InjectDukpt(int idx) {
    int iRet;

    // Buffer do "key block" que será enviado para o PED.
    // 184 bytes é o tamanho esperado pelo c() para esse formato.
    uchar ucKeyBlock[184];

    //  3DES double-length)
    // - tipo da chave (PED_TIK normalmente: Transaction/Initial Key para DUKPT)
    uchar ucDstKeyIdx, ucDstKeyLen;
    uchar ucDstKeyType;

    // Modo de KCV (normalmente 0x01 = KCV por cifrar zeros e pegar alguns bytes)
    uchar ucKcvMode;

    // Saída do KCV (aqui você usa 8 bytes)
    unsigned char szKcvOutput[8];

    // KSN do DUKPT (10 bytes)
    // Obs: você está fixando um KSN de exemplo
    uchar ksn[10] = {0XFF,0XFF,0XF1,0X23,0X45,0X00,0X00,0X00,0X00,0X00};

    // Chave base/IK/TIK (16 bytes)
    // Obs: você está usando 0x01 repetido (apenas exemplo)
    uchar key[16] = {0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01};

    ksn[0] = idx;

    // Zera buffers
    memset(szKcvOutput, 0, sizeof(szKcvOutput));
    memset(ucKeyBlock, 0, sizeof(ucKeyBlock));

    // =========================
    // 1) Define metadados da chave
    // =========================
    ucDstKeyLen  = 16;       // 16 bytes = 3DES double-length (2-key)
    ucKcvMode    = 0x01;     // modo de cálculo/uso do KCV
    ucDstKeyType = PED_TIK;  // tipo: TIK (DUKPT)
    ucDstKeyIdx  = idx;       // slot destino (índice 1)

    // =========================
    // 2) Monta o KeyBlock no formato que o PED espera
    // =========================

    // Byte 0: geralmente indica algum "modo/versão/flag" do bloco.
    // (No seu caso 0x03, depende do manual da OsPedWriteTIK)
    ucKeyBlock[0] = 0x03;

    // Byte 3: índice/slot destino onde vai gravar
    ucKeyBlock[3] = ucDstKeyIdx;

    // Byte 11: tipo da chave (PED_TIK)
    ucKeyBlock[11] = ucDstKeyType;

    // Byte 12: tamanho da chave (16)
    ucKeyBlock[12] = ucDstKeyLen;

    // A partir do byte 13: você coloca os dados da chave em claro (ou no formato exigido)
    memcpy(ucKeyBlock + 13, key, ucDstKeyLen);

    // Em algum offset específico do bloco, você injeta o KSN (10 bytes)
    // Esse offset "13+24+1+128+8" é layout interno do keyblock:
    // 13  -> começo da área de dados
    // +24 -> área reservada (muito comum para header/atributos)
    // +1  -> 1 byte do KcvMode
    // +128-> área reservada (muitas vezes para key data/field fixo)
    // +8  -> 8 bytes do KCV antes do KSN
    memcpy(ucKeyBlock + 13 + 24 + 1 + 128 + 8, ksn, 10);

    // Aqui você grava o KcvMode em "13+24"
    // (ou seja, após 24 bytes depois do offset 13)
    ucKeyBlock[13 + 24] = ucKcvMode;

    // =========================
    // 3) Calcula o KCV da chave
    // =========================
    // Você está cifrando 8 bytes de zero com a chave (key)e guardando a saída em szKcvOutput.
    // Normalmente o KCV é os 3 primeiros bytes (ou 6 hex chars), mas aqui você guarda 8 bytes.

    // ASSINATURA (pelo seu uso): OsDES(input8, output, key, keyLen, mode)
    // mode=1 possivelmente significa "encrypt"
    OsDES("\x00\x00\x00\x00\x00\x00\x00\x00", szKcvOutput, key, sizeof(key), 1);

    // Copia o KCV para dentro do bloco no offset "13+24+1+128"
    // ou seja: logo depois da área reservada, após KcvMode, e após um bloco de 128.
    memcpy(ucKeyBlock + 13 + 24 + 1 + 128, szKcvOutput, sizeof(szKcvOutput));

    // =========================
    // 4) Escreve a chave no PED
    // =========================
    iRet = OsPedWriteTIK(ucKeyBlock);
    OsLog(LOG_DEBUG, "OsPedWriteTIK>%d[%d]", ucDstKeyIdx, iRet);
    return iRet;
}
