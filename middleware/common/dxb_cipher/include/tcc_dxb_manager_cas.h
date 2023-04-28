/*******************************************************************************

*   Copyright (c) Telechips Inc.


*   TCC Version 1.0

This source code contains confidential information of Telechips.

Any unauthorized use without a written permission of Telechips including not
limited to re-distribution in source or binary form is strictly prohibited.

This source code is provided "AS IS" and nothing contained in this source code
shall constitute any express or implied warranty of any kind, including without
limitation, any warranty of merchantability, fitness for a particular purpose
or non-infringement of any patent, copyright or other third party intellectual
property right.
No warranty is made, express or implied, regarding the information's accuracy,
completeness, or performance.

In no event shall Telechips be liable for any claim, damages or other
liability arising from, out of or in connection with this source code or
the use in the source code.

This source code is provided subject to the terms of a Mutual Non-Disclosure
Agreement between Telechips and Company.
*
*******************************************************************************/
#ifndef	_TCC_DXB_MANAGER_CAS_H_
#define	_TCC_DXB_MANAGER_CAS_H_

/********************************************************************
 Header Files
 ********************************************************************/
#include "tcc_dxb_interface_cipher.h"

/***************************************************************
Macro definition
***************************************************************/


/***************************************************************
Type definition
***************************************************************/
#define	ASE_128KEY_SIZE		16
#define	ASE_192KEY_SIZE		24
#define	ASE_256KEY_SIZE		32

#define DES_SINGLE_KEY_SIZE	8
#define DES_DOUBLE_KEY_SIZE	16
#define DES_TRIPLE_2KEY_SIZE	16
#define DES_TRIPLE_3KEY_SIZE	24

#if 0
/* The Algorithm of the cipher block */
enum ALGORITHM_TYPE
{
	TCC_CHIPHER_ALGORITM_AES = 0,
	TCC_CHIPHER_ALGORITM_DES,
	TCC_CHIPHER_ALGORITM_MULTI2,
	TCC_CHIPHER_ALGORITM_MULTI2_1,
	TCC_CHIPHER_ALGORITM_MAX
};

/* The Algorithm of the operation mode */
enum OPERATION_MODE_TYPE
{
	TCC_CHIPHER_OPMODE_ECB = 0,
	TCC_CHIPHER_OPMODE_CBC,
	TCC_CHIPHER_OPMODE_CFB,
	TCC_CHIPHER_OPMODE_OFB,
	TCC_CHIPHER_OPMODE_CTR,
	TCC_CHIPHER_OPMODE_CTR_1,
	TCC_CHIPHER_OPMODE_CTR_2,
	TCC_CHIPHER_OPMODE_CTR_3,
	TCC_CHIPHER_OPMODE_MAX
};

/* The Key Option for AES */ 
enum AES_MODE_TYPE
{
	TCC_CHIPHER_AES_128KEY =0,
	TCC_CHIPHER_AES_192KEY,
	TCC_CHIPHER_AES_256KEY_1,
	TCC_CHIPHER_AES_256KEY_2,
	TCC_CHIPHER_AES_KEYMAX,
};

/* The Key Option for DES */ 
enum DES_MODE_TYPE
{
	TCC_CHIPHER_DES_SINGLE =0,
	TCC_CHIPHER_DES_DOUBLE,
	TCC_CHIPHER_DES_TRIPLE_2KEY,
	TCC_CHIPHER_DES_TRIPLE_3KEY,
	TCC_CHIPHER_DES_KEYMAX,
};

/* The Parity bit Option for DES */ 
enum DES_PARITY_TYPE
{
	TCC_CHIPHER_DES_LSB_PRT =0,
	TCC_CHIPHER_DES_MSB_PRT,
	TCC_CHIPHER_DES_PARITYMAX,
};

/* The Key Option for Multi2 */ 
enum MILTI2_KEY_TYPE
{
	TCC_CHIPHER_KEY_MULTI2_DATA = 0,
	TCC_CHIPHER_KEY_MULTI2_SYSTEM,
	TCC_CHIPHER_KEY_MULTI2_MAX
};

/**
algorithm			: AES, DES, Multi2 	refer to ALGORITHM_TYPE
operation_mode		: ECB, CBC, ... 		refer to OPERATION_MODE_TYPE
algorithm_mode		: AES		-> refer to AES_MODE_TYPE
						DES	-> refer to DES_MODE_TYPE
						Multi2 	-> not used
multi2Rounds		: Multi2		-> round_count (Variable)
						AES, DES  -> not  used
**/
typedef struct TCC_CIPHER_ModeSettings
{
	unsigned int	algorithm;		
	unsigned int	operation_mode;
	unsigned int	algorithm_mode;
	unsigned int	multi2Rounds;
} TCC_CIPHER_ModeSettings;
 
/**
p_key_data			: data key
key_length			: data key_length
p_init_vector		: initial vector 
vector_length		: vector length
p_Systemkey_data	: system key data (used to only multi2)
Systemkey_length	: system key_length(used to only multi2)
**/
 typedef struct TCC_CIPHER_KeySettings
 {
	 unsigned char *p_key_data;
	 unsigned int key_length;
	 unsigned char *p_init_vector;				 // ������� �ʴ� ��� NULL
	 unsigned int vector_length;				 // ������� �ʴ� ��� '0'
	 unsigned char *p_Systemkey_data;				 // ������� �ʴ� ��� NULL
	 unsigned int Systemkey_length;			 // ������� �ʴ� ��� '0'
	 unsigned int Key_flag;			 		// 10: even key, 11:odd key
} TCC_CIPHER_KeySettings;

#endif

 
 /***************************************************************
   Function definition
 ***************************************************************/
#if 0
int TCC_DxB_CAS_KeySwap (unsigned char *srckey, int size);
#endif
 int TCC_DxB_CAS_Open(
	 unsigned int algorithm,		
	 unsigned int operation_mode,
	 unsigned int algorithm_mode,  
	 unsigned int multi2Rounds	 
 );
int TCC_DxB_CAS_OpenSWMulti2(
	unsigned int algorithm,	   
	unsigned int operation_mode,
	unsigned int algorithm_mode,	
	unsigned int multi2Rounds,
	unsigned char * sysKey
);
int TCC_DxB_CAS_Close(void);
int TCC_DxB_CAS_CloseSWMulti2(void);
int TCC_DxB_CAS_SetKey
(
	 unsigned char *p_key_data,
	 unsigned int key_length,
	 unsigned char *p_init_vector,				 // ������� �ʴ� ��� NULL
	 unsigned int vector_length,				 // ������� �ʴ� ��� '0'
	 unsigned char *p_Systemkey_data,				 // ������� �ʴ� ��� NULL
	 unsigned int Systemkey_length,				 // ������� �ʴ� ��� '0'
	 unsigned int key_flag			 // even or odd key
 );

int TCC_DxB_CAS_SetKeySWMulti2
(
	unsigned char parity,			//typedef enum {TCCDEMUX_DESC_ODD,	TCCDEMUX_DESC_EVEN } TCCDEMUX_DESC_ODD_EVEN;
	unsigned char *p_key_data,
	unsigned int key_length,
	unsigned char *p_init_vector,				// ������� �ʴ� ��� NULL
	unsigned int vector_length				// ������� �ʴ� ��� '0'
);

#endif

