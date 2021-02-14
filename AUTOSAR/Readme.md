Autosar Guidelines C++14 example code compile list(1-169)

Guidelines for the use of the C++14 language in critical and safety-related systems (with Sample code) By AUTOSAR 
https://www.autosar.org/fileadmin/user_upload/standards/adaptive/17-03/AUTOSAR_RS_CPP14Guidelines.pdf

ここで処理している内容は、dockerで作業している。

```
$ docker run -it kaizenjapan/autosar11 /bin/bash
```

# 目的(purpose)
AutosarのC++ GuidelineをOS, 制御のプログラムで利用するにあたって、以下を検討する。
(1)hosted, freestandingのどちらを基本にすべきか。(2)C++2014,C++2017, C++202aのどれを用いると良いか。
(3)どの処理系を併用すると良いか。
-std=c++14, -std=c++17, -std=c++2aの3種類で、複数のコンパイラでコンパイルすることにより、誤(error)、警告(warning)、関数・変数連携(link)、出力(output)、にどのような影響があるかを確認する。
# 成果(outcome)
複数の処理系の特徴が明確になる。
各標準段階の違いを明確にする。
hostedまたはfreestandingの特徴と課題を明確にする。

# 編纂器(Compiler)
###clang++ --version
clang version 6.0.0 (tags/RELEASE_600/final)
Target: x86_64-apple-darwin17.4.0

###g++-8 --version
g++-8 (Homebrew GCC 8.1.0) 8.1.0
Copyright (C) 2018 Free Software Foundation, Inc.

#凡例(note)
##算譜状態(state of code)

|番号|状態|
|--:|:--|
| 0 | コンパイルエラー |
| 1 | リンクエラー |
| 2 | 実行時エラー |
| 3 | 警告 |
| 4 | 実行結果検討中 |
| 5 | 実行結果十分 |

# 分類(category)

|項目名|内容|
|:--|:--|
| 年 | 各年版の違い |
| c/g | clang++,g++の違い |
| f/h | freestanding/hosted対応 |

## freestanding
C++N4606 Table 17 — C++ headers for freestanding implementations

|Subclause No.| Subclause Title| Header(s)|
|:--|:--|:--|
|||\<ciso646\>|
|18.2| Types |\<cstddef\>|
|18.3| Implementation properties| \<cfloat\> \<limits\> \<climits\>|
|18.4| Integer types| \<cstdint\>|
|18.5| Start and termination| \<cstdlib\>|
|18.6| Dynamic memory management| \<new\>|
|18.7| Type identification| \<typeinfo\>|
|18.8| Exception handling |\<exception\>|
|18.9| Initializer lists |\<initializer_list\>|
|18.10| Other runtime support| \<cstdalign\> \<cstdarg\> \<cstdbool\>|
|20.15| Type traits| \<type_traits\>|
|29| Atomics |\<atomic\>|

# 一覧(list)
|  |  |  |  | Clang++ |  |  | g++ |  |  |  |  |  |  |  |
|:--|:--|:--|:--|--:|--:|:--|--:|--:|:--|:--|:--|:--|:--|:--|
| No. | Rule No. | Title | URL | 2014 | 2017 | 202a | 2014 | 2017 | 202a | 年 | c/g | f/h | ソースの状態 | 規則への意見 |
| 1 | A0-1-1 | A project shall not contain instances of non-volatile variables | https://qiita.com/kaizen_nagoya/items/4bde8f21ab059b96cf2a | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 2 | A0-1-2  | The value returned by a function | https://qiita.com/kaizen_nagoya/items/e8a08304c28a422bc892 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 3 | A0-1-3  | Every static function or private method of a class shall be used. | https://qiita.com/kaizen_nagoya/items/14d24d71c41cde15ee2e | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 4 | A0-4-1 | Floating-point implementation shall comply | https://qiita.com/kaizen_nagoya/items/65ca21638e224cd07b8c | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 5 | A0-4-2  | Type long double shall not be used. | https://qiita.com/kaizen_nagoya/items/b4296f87f6c5aedd4f77 | 5 | 5 | 5 | 5 | 5 | 5 |  |  |  |  |  |
| 6 | A1-1-1  | All code shall conform to ISO/IEC 14882:2014 | https://qiita.com/kaizen_nagoya/items/7e815f0fafeea19746eb | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 7 | A2-2-1 | Only those characters specified in the C++ Language | https://qiita.com/kaizen_nagoya/items/5d93fc5964039a9b908e | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 8 | A2-5-1 | Trigraphs shall not be used. | https://qiita.com/kaizen_nagoya/items/4fd4828566cdd407b98d | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  | 目的に合致した警告 | 規則の方向性が不適切 |
| 9 | A2-6-1 | Digraphs shall not be used. | https://qiita.com/kaizen_nagoya/items/fc3b25296cec3f02000e | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  | 対象が原文で註釈 | 規則の方向性が不適切 |
| 10 | A2-8-1 | The character ¥ shall not occur as a last character of a C++ comment. | https://qiita.com/kaizen_nagoya/items/24101c8462f144366b11 | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  | 目的に合致した警告 |  |
| 11 | A2-8-2 | Sections of code shall not be ﾒcommented outﾓ. | https://qiita.com/kaizen_nagoya/items/da023f75c06843be8abe | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  | 註釈に関する出力は無理 | 本書の例がこの規則に違反多数 |
| 12 | A2-8-3 | All declarations of “user-defined” types, static and non-static data members,functions and methods  | https://qiita.com/kaizen_nagoya/items/26105b01a9a1527d5ded | 3 | 3 | 3 | 4 | 4 | 4 |  | 警告有無 |  |  |  |
| 13 | A2-8-4  | C-style comments shall not be used. | https://qiita.com/kaizen_nagoya/items/446fffd9e984e90e4995 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  | 註釈に関する出力は無理 |  |
| 14 | A2-11-1 | An identifier declared in an inner scope | https://qiita.com/kaizen_nagoya/items/8e528c3d64d7ab4bfacb | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 15 | A2-11-2 | A ﾒusingﾓ name shall be a unique identifier | https://qiita.com/kaizen_nagoya/items/98bd094966a6b472f9f0 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 16 | A2-11-3 | A ﾒuser-definedﾓ type name | https://qiita.com/kaizen_nagoya/items/1bdfbcb1fbbba1f2d397 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 17 | A2-11-4 | The identifier name of a non-member object | https://qiita.com/kaizen_nagoya/items/47a3c88d930872ed8f3f | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 18 | A2-11-5  | An identifier name of a non-member object or function | https://qiita.com/kaizen_nagoya/items/1e54e0e7c6fcf8773f32 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 19 | A2-14-1 | Only those escape sequences | https://qiita.com/kaizen_nagoya/items/1196f1d2fe001db438a3 | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  | 目的に合致した警告 |  |
| 20 | A2-14-2 | String literals with different encoding prefixes | https://qiita.com/kaizen_nagoya/items/768688bcb5f1b93b884a | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  | 対象が原文で註釈 |  |
| 21 | A2-14-3 | Type wchar_t shall not be used. | https://qiita.com/kaizen_nagoya/items/335e27f6ee54362acac0 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 22 | A3-1-1 | One Definition Rule | https://qiita.com/kaizen_nagoya/items/2734ad5b4190035309cf | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 23 | A3-1-2 | Header files, that are defined locally in the project | https://qiita.com/kaizen_nagoya/items/646ec06b8d68d3b8dc3f | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 24 | A3-1-4 | When an array with external linkage is declared | https://qiita.com/kaizen_nagoya/items/347a7fb02e40c9903206 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 25 | A3-3-1 | Objects or functions with external linkage | https://qiita.com/kaizen_nagoya/items/d1a3b10fa304021ca9d1 | 4 | 4 | 4 | 4 | 4 | 4 |  |  | h | main関数 |  |
| 26 | A3-3-2 | Non-POD type objects with static storage duration | https://qiita.com/kaizen_nagoya/items/f4fe7e72a72765b81cb9 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 27 | A3-9-1 | Fixed width integer types | https://qiita.com/kaizen_nagoya/items/f64b96f505fdc4033a56 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 28 | A4-5-1 | Expressions with type enum or enum class | https://qiita.com/kaizen_nagoya/items/db3f1d802bd383bfbcf3 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 29 | A4-7-1 | An integer expression shall not lead to data loss. | https://qiita.com/kaizen_nagoya/items/849f0ceb1ccbc4af88b7 | 3 | 3 | 3 | 4 | 4 | 4 |  | 警告有無 |  |  |  |
| 30 | A4-10-1  | Only nullptr literal | https://qiita.com/kaizen_nagoya/items/70f76c48c7e2b5e7f293 | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  | 目的に合致した警告 |  |
| 31 | A5-0-1 | The value of an expression | https://qiita.com/kaizen_nagoya/items/e407be7a5efe61967e5b | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 32 | M5-0-7 | There shall be no explicit floating-integral conversions | https://qiita.com/kaizen_nagoya/items/5ddafb4311056c67e956 | 4 | 4 | 4 | 1 | 1 | 1 |  | エラーの無有 |  |  |  |
| 33 | A5-0-2  | The condition of an if-statement | https://qiita.com/kaizen_nagoya/items/b448d148c3038c97be0a | 4 | 4 | 4 | 3 | 3 | 3 |  | 警告無有 |  |  |  |
| 34 | A5-0-3 | The declaration of objects | https://qiita.com/kaizen_nagoya/items/6cb3f621c5667459a688 | 4 | 4 | 4 | 3 | 3 | 3 |  | 警告無有 |  |  |  |
| 35 | A5-1-1 | Literal values | https://qiita.com/kaizen_nagoya/items/57d9c9bd37fb86c6c2cd | 2 | 2 | 2 | 2 | 2 | 2 |  |  |  |  |  |
| 36 | A5-1-2 | Variables shall not be implicitly captured in a lambda expression. | https://qiita.com/kaizen_nagoya/items/0fd6e6c28795266c2bcb | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 37 | A5-1-3 | Parameter list (possibly empty) | https://qiita.com/kaizen_nagoya/items/4e63ffe10b5fe817cb47 | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 38 | A5-1-4 | A lambda expression object | https://qiita.com/kaizen_nagoya/items/5a59bed7bc2c71f92058 | 4 | 4 | 4 | 3 | 3 | 3 |  | 警告無有 |  |  |  |
| 39 | A5-1-5 | If a lambda expression is used in the same scope | https://qiita.com/kaizen_nagoya/items/0e36c8b740984a933fc1 | 2 | 2 | 2 | 2 | 2 | 2 |  |  |  |  |  |
| 40 | A5-1-6  | Return type of a non-void return type lambda expression | https://qiita.com/kaizen_nagoya/items/aa4f515d3f60551f71b3 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 41 | A5-1-7  | The underlying type of lambda expression | https://qiita.com/kaizen_nagoya/items/6e77243f7ce1177def7c | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 42 | A5-1-8 |  Lambda expressions should not be defined inside another lambda expression. | https://qiita.com/kaizen_nagoya/items/9a3ba743b2ca4c1af9f8 | 3 | 3 | 3 | 4 | 4 | 4 |  | 警告有無 |  |  |  |
| 43 | A5-2-1  | dynamic_cast should not be used. | https://qiita.com/kaizen_nagoya/items/21e18e7b7bc22a106ec4 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 44 | A5-2-2  | Traditional C-style casts shall not be used. | https://qiita.com/kaizen_nagoya/items/f200e9af97c3af2eaed0 | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 45 | A5-2-3 |  A cast shall not remove any const or volatile qualification | https://qiita.com/kaizen_nagoya/items/cbaaa8af337ad3715f6a | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 46 | A5-2-4 |  reinterpret_cast shall not be used | https://qiita.com/kaizen_nagoya/items/5dd12720721441dc37c0 | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 47 | A5-2-5 |  An array shall not be accessed beyond its range. | https://qiita.com/kaizen_nagoya/items/0f1a511222ecb44761d1 | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 48 | A5-3-1  | Evaluation of the operand to the typeid operator | https://qiita.com/kaizen_nagoya/items/1382c63f4b80703d4591 | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 49 | A5-5-1 |  The right hand operand of the integer division or remainder operators | https://qiita.com/kaizen_nagoya/items/c811cfb4f50dc53cbbc7 | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 50 | A5-10-1 |  A pointer to member virtual function | https://qiita.com/kaizen_nagoya/items/ddd2a9f49af80f2f7440 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 51 | A5-16-1 |  The ternary conditional operator | https://qiita.com/kaizen_nagoya/items/80fc01874fd2a01b7b22 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 52 | A6-4-1  | A switch statement shall have at least two case-clauses, | https://qiita.com/kaizen_nagoya/items/82a6af1d965b0406d818 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 53 | A6-5-1  | A for-loop that loops through all elements of the container | https://qiita.com/kaizen_nagoya/items/1ea4043872d9a0284c9f | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 54 | A6-5-2  | A for loop shall contain a single loop-counter | https://qiita.com/kaizen_nagoya/items/cb8482d3e8a543b4cf51 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 55 | A6-6-1  | The goto statement | https://qiita.com/kaizen_nagoya/items/c9ea5cc95dfbe82af8a3 | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 56 | A7-1-1  | Constexpr or const specifiers | https://qiita.com/kaizen_nagoya/items/01357990929b34246d52 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 57 | A7-1-2 |  The constexpr specifier | https://qiita.com/kaizen_nagoya/items/2863bba0d7bfd8f59e0d | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 58 | A7-1-3 |  CV-qualifiers shall be placed on the right hand side | https://qiita.com/kaizen_nagoya/items/574ea63596bd74e686de | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 59 | A7-1-4 |  The register keyword shall not be used. | https://qiita.com/kaizen_nagoya/items/2e25e8b4ef4cdaaf2bab | 3 | 3 | 3 | 4 | 3 | 3 | g++2014だけ警告なし |  |  | C++2017以降警告 |  |
| 60 | A7-1-5 | The auto specifier | https://qiita.com/kaizen_nagoya/items/eb470825727b6ce7a3da | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 61 | A7-1-6 | The typedef specifier shall not be used. | https://qiita.com/kaizen_nagoya/items/9f1eb6f990f8111e3406 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 62 | A7-1-7 | Each identifier shall be declared on a separate line. | https://qiita.com/kaizen_nagoya/items/263eff2e5f420b46ccde | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 63 | A7-1-8 | A non-type specifier | https://qiita.com/kaizen_nagoya/items/9bdf109fa1c4251e1dec | 4 | 4 | 4 | 4 | 4 | 4 |  | clang++値0 |  |  |  |
| 64 | A7-2-1 | An expression with enum underlying type | https://qiita.com/kaizen_nagoya/items/781ca0c57210c52b47d8 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 65 | A7-2-2 | Enumeration underlying base type | https://qiita.com/kaizen_nagoya/items/0cbf42e658feb36ca71b | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 66 | A7-2-3 | Enumerations shall be declared as scoped enum classes. | https://qiita.com/kaizen_nagoya/items/01feb3928e86737c7e2b | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 67 | A7-2-4 | In an enumeration, either (1) none, (2) the first or (3) all enumerators shall be initialized. | https://qiita.com/kaizen_nagoya/items/a51467ac7c99f6d75ff5 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 68 | A7-4-1 | The asm declaration shall not be used. | https://qiita.com/kaizen_nagoya/items/1ae2c287cf22d9cba8ca | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 69 | A7-5-1 | A function shall not return a reference or a pointer to a parameter that is passed by reference to const. | https://qiita.com/kaizen_nagoya/items/5f4dc3e715f09fc37c2d | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 70 | A7-5-2 | Functions shall not call themselves | https://qiita.com/kaizen_nagoya/items/76c9f24cf70dbc4dcb08 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 71 | A8-2-1 | When declaring function templates, the trailing return type syntax shall be used | https://qiita.com/kaizen_nagoya/items/74984b8d7744c8bacee7 | 4 | 4 | 4 | 3 | 3 | 3 |  | 警告無有 |  |  |  |
| 72 | A8-4-1 | Functions shall not be defined using the ellipsis notation. | https://qiita.com/kaizen_nagoya/items/3ef74d89eb92626e3d0e | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 73 | A8-4-2 | All exit paths from a function with non-void return type | https://qiita.com/kaizen_nagoya/items/5f09b43f8e99eec0effe | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 74 | A8-5-1 | In an initialization list, the order of initialization | https://qiita.com/kaizen_nagoya/items/bfa7aa64a4f97b146c35 | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 75 | A8-5-2 | Braced-initialization {}, without equals sign, | https://qiita.com/kaizen_nagoya/items/8476dcf33bb05c45fea7 | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 76 | A8-5-3 | A variable of type auto shall not be initialized using {} or ={} bracedinitialization. | https://qiita.com/kaizen_nagoya/items/a3d233a2763a4462980a | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 77 | A8-5-4 | A constructor taking parameter of type std::initializer_list | https://qiita.com/kaizen_nagoya/items/259a4bfc47b4b88090ae | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 78 | A9-3-1 | Member functions shall not return non-const "raw" pointers or references | https://qiita.com/kaizen_nagoya/items/069333097163852d2f69 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 79 | A9-6-1 | Bit-fields shall be either unsigned integral, or enumeration | https://qiita.com/kaizen_nagoya/items/ed1be49a081ed2b19a79 | 4 | 4 | 4 | 3 | 3 | 3 |  | 警告無有 |  |  |  |
| 80 | A10-1-1 | Class shall not be derived from more than one base class | https://qiita.com/kaizen_nagoya/items/797a07a7ad66364221f9 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 81 | A10-2-1 | Non-virtual member functions | https://qiita.com/kaizen_nagoya/items/7ea149c0bb63c2985875 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 82 | A10-3-1 | Virtual function declaration shall contain exactly one of the three specifiers | https://qiita.com/kaizen_nagoya/items/79d09bdcaf698feb248f | 3 | 3 | 3 | 4 | 4 | 4 |  | 警告有無 |  |  |  |
| 83 | A10-3-2 | Each overriding virtual function shall be declared with the override or final specifier. | https://qiita.com/kaizen_nagoya/items/c14fcee78de768f60a3a | 3 | 3 | 3 | 4 | 4 | 4 |  | 警告有無 |  |  |  |
| 84 | A10-3-3 | Virtual functions shall not be introduced in a final class. | https://qiita.com/kaizen_nagoya/items/9085d3c5b2fec92a5a0c | 3 | 3 | 3 | 4 | 4 | 4 |  | 警告有無 |  |  |  |
| 85 | A10-3-5 | A user-defined assignment operator shall not be virtual. | https://qiita.com/kaizen_nagoya/items/2384abacb09f69a4e929 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 86 | A11-0-1 | A non-POD type should be defined as class. | https://qiita.com/kaizen_nagoya/items/a2e37d53779981197252 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 87 | A11-0-2 | A type defined as struct | https://qiita.com/kaizen_nagoya/items/c2bee821a1946bb04440 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 88 | A11-3-1 | Friend declarations shall not be used. | https://qiita.com/kaizen_nagoya/items/96ed8fec21161f271e05 | 3 | 3 | 3 | 4 | 4 | 4 |  | 警告有無 |  |  |  |
| 89 | A12-0-1 | If a class defines any special member function "=default", "=delete" or with a function definition, | https://qiita.com/kaizen_nagoya/items/ae1518ad49e3332fe162 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 90 | A12-1-1 | Constructors shall explicitly initialize | https://qiita.com/kaizen_nagoya/items/d1789f272955dcbccfbc | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 91 | A12-1-2 | Both NSDMI and a non-static member initializer in a constructor shall not be used in the same type. | https://qiita.com/kaizen_nagoya/items/7738a03d06c877f7c6bd | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 92 | A12-1-3 | If all user-defined constructors of a class initialize data members | https://qiita.com/kaizen_nagoya/items/4585dd1c794c1568f864 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 93 | A12-1-4 | All constructors that are callable with a single argument of fundamental type shall be declared explicit. | https://qiita.com/kaizen_nagoya/items/3f7c5457c380db89c657 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 94 | A12-4-1 | Destructor of a base class shall be public virtual, public override or protected non-virtual. | https://qiita.com/kaizen_nagoya/items/f702d31101160c0b4125 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 95 | A12-4-2 | If a public destructor of a class is non-virtual, then the class should be declared final. | https://qiita.com/kaizen_nagoya/items/7d6481eade0e034a4caa | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 96 | A12-6-1 | All class data members that are initialized by the constructor shall be initialized using member initializers. | https://qiita.com/kaizen_nagoya/items/42b210f6cc2f9c4771ca | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 97 | A12-7-1 | If the behavior of a user-defined special member function | https://qiita.com/kaizen_nagoya/items/97cdc20beef0c962c420 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 98 | A12-8-1 | Move and copy constructors shall only move and respectively copy base classes and data members of a class, without any side effects. | https://qiita.com/kaizen_nagoya/items/fa64a644d38651fc2393 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 99 | A12-8-3 | User-defined copy and move assignment operators | https://qiita.com/kaizen_nagoya/items/137d65891204db130cdb | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 100 | A12-8-3 | Moved-from object shall not be read-accessed. | https://qiita.com/kaizen_nagoya/items/b5a2114ccee52370022d | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 101 | A12-8-4 | Move constructor shall not initialize its class members and base classes using copy semantics. | https://qiita.com/kaizen_nagoya/items/93d35dc76f641ad758d9 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 102 | A12-8-5 | A copy assignment and a move assignment operators shall handle selfassignment. | https://qiita.com/kaizen_nagoya/items/3f5ba14e23fb437bb728 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 103 | A12-8-6 | Copy and move constructors and copy assignment and move assignment operators | https://qiita.com/kaizen_nagoya/items/c4f32f4741203b35c867 | 1 | 1 | 1 | 1 | 1 | 1 |  |  |  |  |  |
| 104 | A12-8-7 | Assignment operators should be declared with the ref-qualifier &. | https://qiita.com/kaizen_nagoya/items/1eadbfa6b9d7b1197019 | 4 | 4 | 4 | 4 | 4 | 4 |  |  | h | main関数 |  |
| 105 | A13-1-1 | User-defined literals shall not be used. | https://qiita.com/kaizen_nagoya/items/5973a291c1ca5be947f3 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 106 | A13-1-2 | User defined suffixes of the user defined literal operators | https://qiita.com/kaizen_nagoya/items/6ecd73ac86894a60a914 | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 107 | A13-1-3 | User defined literals operators shall only perform conversion of passed parameters. | https://qiita.com/kaizen_nagoya/items/1efe8faaf6c395ccf6e6 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 108 | A13-2-1 | An assignment operator shall return a reference to "this" | https://qiita.com/kaizen_nagoya/items/36844fa5f0c5c1c66f97 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 109 | A13-2-2 | A binary arithmetic operator and a bitwise operator shall return a "prvalue" | https://qiita.com/kaizen_nagoya/items/441e5b8fb51882c3fb79 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 110 | A13-2-3 | A relational operator shall return a boolean value. | https://qiita.com/kaizen_nagoya/items/9a7125591c662b3e7c3d | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 111 | A13-3-1 | A function that contains "forwarding reference" as its argument | https://qiita.com/kaizen_nagoya/items/0ee1fa1656b38dd9daea | 4 | 4 | 4 | 4 | 4 | 4 |  |  | h | main関数 |  |
| 112 | A13-5-1 | If "operator[]" is to be overloaded with a non-const version, const version | https://qiita.com/kaizen_nagoya/items/894978aede607d036338 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 113 | A13-6-1 | Digit sequences separators' shall only be used | https://qiita.com/kaizen_nagoya/items/f5294fe80ef466afd0c9 | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 114 | A14-1-1 | A template should check if a specific template argument is suitable for this template. | https://qiita.com/kaizen_nagoya/items/da5920fd4d02cda16244 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 115 | A14-7-1 | A type used as a template argument shall provide all members that are used by the template. | https://qiita.com/kaizen_nagoya/items/8e2e7d2fdf2a849ca3df | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 116 | A14-8-1 | The set of function overloads | https://qiita.com/kaizen_nagoya/items/5c770f7134a656acda56 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 117 | A15-0-1 | A function shall not exit with an exception | https://qiita.com/kaizen_nagoya/items/9d30b5cb566eb60195eb | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 118 | A15-0-2 | At least the basic guarantee for exception safety | https://qiita.com/kaizen_nagoya/items/147a349705beb0c4365b | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 119 | A15-0-3 | Exception safety guarantee of a called function | https://qiita.com/kaizen_nagoya/items/cd6d0363de1a65993156 | 4 | 4 | 4 | 4 | 4 | 4 |  |  | h | main関数 |  |
| 120 | A15-0-4 | Unchecked exceptions shall be used to represent errors  | https://qiita.com/kaizen_nagoya/items/02bc2e0e2eced42f67a9 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 121 | A15-0-5 | Checked exceptions shall be used to represent errors | https://qiita.com/kaizen_nagoya/items/f899052eb10f567ddc02 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 122 | A15-0-7 | Exception handling mechanism | https://qiita.com/kaizen_nagoya/items/882dc5f3caf3ac2c38cb | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 123 | A15-1-1 | Only instances of types derived from std::exception | https://qiita.com/kaizen_nagoya/items/a7724061617d23763faa | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 124 | A15-1-2 | An exception object shall not be a pointer. | https://qiita.com/kaizen_nagoya/items/2b6c9f04d746b0081457 | 2 | 2 | 2 | 2 | 2 | 2 |  |  |  |  |  |
| 125 | A15-1-3 | All thrown exceptions should be unique. | https://qiita.com/kaizen_nagoya/items/4d3d09738fcc92e54af3 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 126 | A15-1-4 | If a function exits with an exception, then before a throw, | https://qiita.com/kaizen_nagoya/items/1bd81adcb9f876b90ce9 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 127 | A15-2-1 | Constructors that are not noexcept | https://qiita.com/kaizen_nagoya/items/9ec4fe3f5f8db648e330 | 2 | 2 | 2 | 2 | 2 | 2 |  |  | h | main関数 |  |
| 128 | A15-2-2 | If a constructor is not noexcept and the constructor cannot finish object initialization, | https://qiita.com/kaizen_nagoya/items/1a398704262be0b30154 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 129 | A15-3-1 | Unchecked exceptions should be handled only in main or thread's main functions. | https://qiita.com/kaizen_nagoya/items/69cc2a200694a25b2bcb | 4 | 4 | 4 | 4 | 4 | 4 |  |  | h | main関数 |  |
| 130 | A15-3-2 | If a function throws a checked exception, it shall be handled when meaningful actions can be taken, otherwise it shall be propagated. | https://qiita.com/kaizen_nagoya/items/6c88de088bb3398ecd9a | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 131 | A15-3-3 | There shall be at least one exception handler to catch all otherwise unhandled exceptions. | https://qiita.com/kaizen_nagoya/items/85532fb8ea8f6e34419b | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 132 | A15-3-4 | Catch-all (ellipsis and std::exception) handlers | https://qiita.com/kaizen_nagoya/items/ef61f73e627f90a2a73b | 2 | 2 | 2 | 2 | 2 | 2 |  |  |  |  |  |
| 133 | A15-3-5 | A class type exception shall be caught by reference or const reference. | https://qiita.com/kaizen_nagoya/items/066e8a41c4f2309ab264 | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 134 | A15-4-1 | Dynamic exception-specification shall not be used. | https://qiita.com/kaizen_nagoya/items/ad42baee9e72ef4d4a96 | 4 | 0 | 0 | 0 | 0 | 0 | Clang++2014だけ実行 |  |  |  |  |
| 135 | A15-4-2 | If a function is declared to be noexcept, noexcept(true) or noexcept(\<true condition\>), then it shall not exit with an exception. | https://qiita.com/kaizen_nagoya/items/8ff53ee960a7e802f9d8 | 2 | 2 | 2 | 2 | 2 | 2 |  |  |  |  |  |
| 136 | A15-4-3 | Function's noexcept specification shall be either identical or more restrictive across all translation units and all overriders. | https://qiita.com/kaizen_nagoya/items/d7f206bd606bf5702785 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 137 | A15-4-4 | A declaration of non-throwing function | https://qiita.com/kaizen_nagoya/items/f3ebb3c11d214d28ddb9 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 138 | A15-4-5 | Checked exceptions that could be thrown from a function | https://qiita.com/kaizen_nagoya/items/a9aba200b706ff1d534a | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 139 | A15-4-6 | Unchecked exceptions should not be specified together with a function declaration. | https://qiita.com/kaizen_nagoya/items/f4ace6e95adeb2335aae | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 140 | A15-5-1 | A class destructor, "delete" operators, move constructor, move assignment operator and "swap" function shall not exit with an exception.  | https://qiita.com/kaizen_nagoya/items/3e3a35013703058894f9 | 2 | 2 | 2 | 2 | 2 | 2 |  |  |  |  |  |
| 141 | A15-5-2 | Program shall not be abruptly terminated. | https://qiita.com/kaizen_nagoya/items/ae391fdcf2ff9a30448b | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 142 | A15-5-3 | The std::terminate() function | https://qiita.com/kaizen_nagoya/items/ec3ecf2d954af0b7a2e7 | 2 | 2 | 2 | 2 | 2 | 2 |  |  |  |  |  |
| 143 | A16-0-1 | The pre-processor shall only be used | https://qiita.com/kaizen_nagoya/items/bb609cedfceb4360d45d | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 144 | A16-2-1 | The ', ", /*, //, ﾂ･ characters | https://qiita.com/kaizen_nagoya/items/48e7dea154f81ac7451d | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 145 | A16-2-2 | There shall be no unused include directives. | https://qiita.com/kaizen_nagoya/items/95263d3f8055b52c8a8a | 4 | 4 | 4 | 4 | 4 | 4 |  | g++vector出力詳細 |  |  |  |
| 146 | A16-2-3 | All used include directives | https://qiita.com/kaizen_nagoya/items/91115f88e10f5a9d595f | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 147 | A16-6-1 | #error directive | https://qiita.com/kaizen_nagoya/items/89457696601ce6dc3c90 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 148 | A16-7-1 | The #pragma directive shall not be used. | https://qiita.com/kaizen_nagoya/items/947bb2d2d8716cfeb72a | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 149 | A17-0-1 | Reserved identifiers, macros and functions in the C++ standard library | https://qiita.com/kaizen_nagoya/items/261a92db3c0d88882e4b | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 150 | A17-1-1 | Use of the C Standard Library | https://qiita.com/kaizen_nagoya/items/a5a6ba962178c22e449d | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 151 | A18-0-2 | The library functions atof, atoi and atol from library \<cstdlib\> shall not be used. | https://qiita.com/kaizen_nagoya/items/5cca62e3977e40a9da8a | 2 | 2 | 2 | 2 | 2 | 2 |  |  |  |  |  |
| 152 | A18-1-1 | C-style arrays | https://qiita.com/kaizen_nagoya/items/2bc721e91acb7e6bcc02 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 153 | A18-1-2 | The std::vector\<bool\> shall not be used. | https://qiita.com/kaizen_nagoya/items/68fb95a5398e3c1c84fc | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 154 | A18-1-3 | The std::auto_ptr shall not be used. | https://qiita.com/kaizen_nagoya/items/20fa46c9cedee7e8fa10 | 4 | 0 | 0 | 3 | 3 | 3 | Clang++2014だけ実行 | g++警告  |  |  |  |
| 155 | A18-1-4 | The std::shared_ptr shall not refer to an array type. | https://qiita.com/kaizen_nagoya/items/646335bdde82ca708ba6 | 2 | 2 | 2 | 2 | 2 | 2 |  |  |  |  |  |
| 156 | A18-1-5 | The std::unique_ptr shall not be passed to a function by const reference. | https://qiita.com/kaizen_nagoya/items/3632b0727fe669218bb0 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 157 | A18-5-1 | Functions malloc, calloc, realloc and free shall not be used. | https://qiita.com/kaizen_nagoya/items/83c13a8e8a82a2e30c1f | 2 | 2 | 2 | 2 | 2 | 2 |  |  |  |  |  |
| 158 | A18-5-2 | Operators new and delete shall not be called explicitly. | https://qiita.com/kaizen_nagoya/items/e410915064ca8fc4542f | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 159 | A18-5-3 | The form of delete operator shall match the form of new operator used to allocate the memory. | https://qiita.com/kaizen_nagoya/items/276cee9af8b621e63a19 | 3 | 3 | 3 | 4 | 4 | 4 |  | 警告有無 |  |  |  |
| 160 | A18-5-4 | If a project has sized or unsized version of operator "delete" globally defined, then both sized and unsized versions shall be defined. | https://qiita.com/kaizen_nagoya/items/5f0467e0c04fbafb3aef | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 161 | A18-5-5 | Memory management functions | https://qiita.com/kaizen_nagoya/items/8cdd57bbe343fe476d67 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |  |  |  |  |
| 162 | A18-5-6 | An analysis shall be performed to analyze the failure modes of dynamic memory management. | https://qiita.com/kaizen_nagoya/items/994f6b2e4708f992e8aa | 2 | 2 | 2 | 2 | 2 | 2 |  |  |  |  |  |
| 163 | A18-9-1 | The std::bind shall not be used | https://qiita.com/kaizen_nagoya/items/2073263b42177dd5de31 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 164 | A18-9-2 | Forwarding values to other functions | https://qiita.com/kaizen_nagoya/items/93438e4c3e347a5bcfbc | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 165 | A18-9-3 | The std::move | https://qiita.com/kaizen_nagoya/items/73917638626275b77bef | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 166 | A18-9-4 | An argument to std::forward | https://qiita.com/kaizen_nagoya/items/a6436146a317bd70246b | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 167 | A23-0-1 | An iterator shall not be implicitly converted to const_iterator. | https://qiita.com/kaizen_nagoya/items/bf70e3d05f362933c004 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
| 168 | A27-0-1 | Inputs from independent components shall be validated. | https://qiita.com/kaizen_nagoya/items/c63b6b1bc1dcc4272f8f | 3 | 3 | 3 | 3 | 3 | 3 |  |  |  |  |  |
| 169 | A27-0-2 |A C-style string shall guarantee sufficient space for data and the null terminator. | https://qiita.com/kaizen_nagoya/items/e6ec4f685b5b956a7f62 | 4 | 4 | 4 | 4 | 4 | 4 |  |  |  |  |  |
|  |  |  |  | Clang++ |  |  | g++ |  |  |  |  |  |  |  |
| No. | Rule No. | Title | URL | 2014 | 2017 | 202a | 2014 | 2017 | 202a | 年 | c/g | f/h | ソースの状態 | 規則への意見 |

## Header file

```c++:autosar.h
#ifndef AUTOSAR_H
#define AUTOSAR_H

/// Autosar Specification of Operating System
/// https://www.autosar.org/fileadmin/user_upload/standards/classic/3-0/AUTOSAR_SWS_OS.pdf
/// The header file below are reserved by AUTOSAR
/// Os.h
/// Std_Types.h
/// Os_Cfg.h
/// MemMap.h

#ifndef FREESTANDING
#include <iostream>
#define start main
#define ShutdownOS() return
#else
#define EXIT_SUCCESS
#endif

#include <cstdlib>

#endif

///C++N4606 
///17.6.1.3 Freestanding implementations [compliance] p.465
///Table 17 — C++ headers for freestanding implementations
///Subclause Header(s)
/// ,, <ciso646>
///18.2, Types <cstddef>
///18.3, Implementation properties <cfloat> <limits> <climits>
///18.4, Integer types <cstdint>
///18.5, Start and termination <cstdlib>
///18.6, Dynamic memory management <new>
///18.7, Type identification <typeinfo>
///18.8, Exception handling <exception>
///18.9, Initializer lists <initializer_list>
///18.1,0 Other runtime support <cstdalign> <cstdarg> <cstdbool>
///20.15, Type traits <type_traits>
///29, Atomics <atomic>

///If there are other header files, freestanding enviroment or other library should be prepare alternative functions.
```
##編纂・実行命令(compile and go shell script)

```shell:cpa.sh
cat ../cpa.sh
#!/bin/sh
echo "$ clang++ $1.cpp -std=c++14 -Wall"
clang++ $1.cpp -std=c++14 -I=. -Wall -o $1l14
if [  -e $1l14 ]; then
./$1l14 $2
rm $1l13
fi
echo "$ clang++ $1.cpp -std=c++17 -Wall"
clang++ $1.cpp -std=c++17 -I=. -Wall -o $1l17
if [  -e $1l17 ]; then
./$1l17 $2
rm $1l17
fi
echo "$ clang++ $1.cpp -std=c++2a -Wall"
clang++ $1.cpp -std=c++2a -I=. -Wall -o $1l2a
if [  -e $1l2a ]; then
./$1l2a $2
rm $1l2a
fi
echo "\r"
echo "$ g++-8 $1.cpp -std=c++14  -Wall"
g++-8 $1.cpp  -std=c++14 -I=. -Wall -o $1g14
if [  -e $1g14 ]; then
./$1g14 $2
rm $1g14
fi
echo "$ g++-8 $1.cpp -std=c++17  -Wall"
g++-8 $1.cpp  -std=c++17 -I=. -Wall -o $1g17
if [  -e $1g17 ]; then
./$1g17 $2
rm $1g17
fi
echo "$ g++-8 $1.cpp -std=c++2a  -Wall" 
g++-8 $1.cpp  -std=c++2a -I=. -Wall -o $1g2a
if [  -e $1g2a ]; then
./$1g2a $2
rm $1g2a
fi
```

 
# 参考文献(reference)

### プログラミング言語教育のXYZ
https://qiita.com/kaizen_nagoya/items/1950c5810fb5c0b07be4
プログラミング言語教育のXYZ(youtube)
https://www.youtube.com/watch?v=He1_tg4px-w&t=486s

###C++N4741 2018
Working Draft, Standard for Programming Language C++
http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/n4741.pdf

C++N4741, 2018 Standard Working Draft on ISO/IEC 14882 sample code compile list
https://qiita.com/kaizen_nagoya/items/3294c014044550896010

### C++N4606 2016
Working Draft, Standard for Programming Language C++
http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/n4606.pdf

C++N4606, 2016符号断片編纂一覧(example code compile list)
 Working Draft 2016, ISO/IEC 14882(1)
https://qiita.com/kaizen_nagoya/items/df5d62c35bd6ed1c3d43/

###　CEDD(Compile Error Driven Design) 
初めての　CEDD(Compile Error Driven Design) ８回直してコンパイル。
https://qiita.com/kaizen_nagoya/items/9494236aa1753f3fd1e1

コンパイルエラーを記録するとよい理由7つ
https://qiita.com/kaizen_nagoya/items/85c0e92b206883140e89

C Puzzle Bookの有り難み5つ、C言語規格及びCコンパイラの特性を認識
https://qiita.com/kaizen_nagoya/items/d89a48c1536a02ecdec9

C言語（C++)に対する誤解、曲解、無理解、爽快。
https://qiita.com/kaizen_nagoya/items/3f3992c9722c1cee2e3a

Qiitaに投稿するCのStyle例(暫定)
https://qiita.com/kaizen_nagoya/items/946df1528a6a1ef2bc0d

C++N4606 Working Draft 2016, ISO/IEC 14882, C++ standardのコード断片をコンパイルするためにしていること
https://qiita.com/kaizen_nagoya/items/a8d7ee2f2e29e76c19c1

コンパイル用shell script C版(clangとgcc)とC++版(clang++とg++)
https://qiita.com/kaizen_nagoya/items/74220c0577a512c2d7da

[C][C++]の国際規格案の例題をコンパイルするときの課題７つ。
https://qiita.com/kaizen_nagoya/items/5f4b155030259497c4de


docker gnu(gcc/g++) and llvm(clang/clang++)
https://qiita.com/drafts/059874ea39c4de64c0f7

## AUTOSAR

AUTOSAR入門
https://qiita.com/kaizen_nagoya/items/5e43b8ef0935c32ee11d

TOPPERS のAUTOSARへの貢献(更新中)
https://qiita.com/kaizen_nagoya/items/d363cf06e2176207b391

AUTOSAR document @ R20-11
https://qiita.com/kaizen_nagoya/items/22a19ac8e7edb6ab8084

# 文書履歴(document history)
ver 0.10 初稿 20180613
ver 0.20 全件記録 20180614
ver 0.21 表の項目統一 20180615
ver 0.22 参考文献追記、はじめの文章に手入れ、見出しに英語追記 20180616 
ver 0.23 表の最後の乱れ修正 20180617
ver 0.24 158, Rule A18-5-2誤植訂正、「編纂・実行命令」・「header file」「C++N4606 Table 17 — C++ headers for freestanding implementations」追記 20180624
ver. 0.25 誤植訂正 20190121
ver. 0.26 みだし変更 20190331
ver. 0.27 はてな　追記 20190429
ver. 0.28 AUTOSAR追記 20201226
ver. 0.29 docker 追記 20210105

<a href="http://b.hatena.ne.jp/entry/s/qiita.com/kaizen_nagoya/items/8ccbf6675c3494d57a76" class="hatena-bookmark-button" data-hatena-bookmark-layout="basic-label-counter" data-hatena-bookmark-lang="ja" title="このエントリーをはてなブックマークに追加"><img src="https://b.st-hatena.com/images/v4/public/entry-button/button-only@2x.png" alt="このエントリーをはてなブックマークに追加" width="20" height="20" style="border: none;" /></a><script type="text/javascript" src="https://b.st-hatena.com/js/bookmark_button.js" charset="utf-8" async="async"></script>
http://b.hatena.ne.jp/guide/bbutton
