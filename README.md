# simple_encrypt_decrypt

加密思路：用两位字符代表的十六进制数表示字符串长度，之后每个字符用两位的十六进制数表示其ascii码。拼接起来即得到密文字符串
解密方法：对密文反推即可。
举例：明文账号字符串"15014953"，加密后的密文“083135303134393533”，前两位08即十六进制8, 31即十六进制49，在ascii码表中49代表数字1，以此类推
