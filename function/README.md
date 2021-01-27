# 概要

## Assembly

| index |  op   |         dst         |         src         | comment                                                                |
| :---: | :---: | :-----------------: | :-----------------: | :--------------------------------------------------------------------- |
|   1   | push  |         rbp         |                     | ベースポインタの値をスタックに退避。rspの値を減らす                    |
|   2   |  mov  |         rbp         |         rsp         | スタックポインタをベースポインタとしてコピー                           |
|   3   |  sub  |         rsp         |        0x10         | スタックを16bit確保                                                    |
|   4   |  mov  | DWORD PTR [rbp-0xc] |         0xa         | ベースポインタから12bit進めたところに10をセット                        |
|   5   |  mov  | DWORD PTR [rbp-0x8] |        0x14         | ベースポインタかた8bit進めたところに20をセット                         |
|   6   |  mov  |         edx         | DWORD PTR [rbp-0x8] | ベースポインタから8bit進んだところにある値(10)をedxレジスタにコピー    |
|   7   |  mov  |         eax         | DWORD PTR [rbp-0xc] | ベースポインタから12bit進んだところにある値(20)をeaxレジスタにコピー   |
|   8   |  mov  |         esi         |         edx         | edxの値(10)をesiにコピー                                               |
|   9   |  mov  |         edi         |         eax         | eaxの値(20)をediにコピー                                               |
|  10   | call  |       0x1149        |                     | add関数を呼んでいる                                                    |
|  11   |  mov  | DWORD PTR [rbp-0x4] |         eax         | ベースポインタから4bit進んだところにeaxの値(add関数の返り値)をコピー   |
|  12   |  mov  |         ecx         | DWORD PTR [rbp-0x4] | ベースポインタから4bit進んだところの値をecxにコピー(printf呼び出し用)  |
|  13   |  mov  |         edx         | DWORD PTR [rbp-0x8] | ベースポインタから8bit進んだところの値をedxにコピー(printf呼び出し用)  |
|  14   |  mov  |         eax         | DWORD PTR [rbp-0xc] | ベースポインタから12bit進んだところの値をeaxにコピー(printf呼び出し用) |
|  15   |  mov  |         esi         |         eax         | eaxの値をesiにコピー                                                   |
|  16   |  lea  |         rdi         |     [rip+0xe65]     | プログラムカウンタを3685bit進めた先のアドレスをrdiにロード             |
|  17   |  mov  |         eax         |         0x0         | eaxに0を代入                                                           |
|  18   | call  |       0x1050        |                     | printf関数を呼んでいる                                                 |
|  19   |  mov  |         eax         |         0x0         | eaxに0を代入                                                           |
|  20   | leave |                     |                     | スタックフレームの解放                                                 |
|  21   |  ret  |                     |                     | 終了                                                                   |

- なぜindex8, 9, 15のように汎用レジスタからインデックスレジスタに一度コピーをしている?
- index16ではなぜ、rip+0xe65にあるアドレスをロードしている? 何の関数?
