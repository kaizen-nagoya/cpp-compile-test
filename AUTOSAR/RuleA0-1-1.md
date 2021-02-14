Autosar Guidelines C++14 example code compile list(1)Rule A0-1-1 A project shall not contain instances of non-volatile variables

Guidelines for the use of the C++14 language in critical and
safety-related systems Sample code compile list(1)
https://www.autosar.org/fileadmin/user_upload/standards/adaptive/17-03/AUTOSAR_RS_CPP14Guidelines.pdf

Autosar Guidelines C++14 example code compile list
https://qiita.com/kaizen_nagoya/items/8ccbf6675c3494d57a76

#目的(purpose)
AutosarのC++ GuidelineをOS, 制御のプログラムで利用するにあたって、(1)hosted, freestandingのどちらを基本にすべきか。(2)C++2014,C++2017, C++202aのどれを用いると良いか, (3)どの処理系を併用すると良いかを検討するため、-std=c++14, -std=c++17, -std=c++2aの3種類で、複数のコンパイラでコンパイルすることにより、誤(error)、警告(warning)、関数・変数連携(link)、出力(output)、にどのような影響があるかを確認する。
#成果(outcome)
複数の処理系の特徴が明確になるとともに、各標準段階, hosted, freestandingの特徴と課題を明確にする。


#A0-1-1.cpp
##算譜(source code)

```c++:A0-1-1.cpp
//Guidelines for the use of the C++14 language in critical and safety-related systems
const char* msg= "Rule A0-1-1 (required, implementation, automated) A project shall not contain instances of non-volatile variables being given values that are not subsequently used.(1) A0-1-1.cpp";
//https://www.autosar.org/fileadmin/user_upload/standards/adaptive/17-03/AUTOSAR_RS_CPP14Guidelines.pdf
// There is no description about Autosar declear hosted or freestanding.
// If the Autosar intended both depending on the cases, autosar.h can choose one.
// Compile with -DHOSTED work as  hosted environment, -DFREESTANDING work as freestanding.

///start AUTOSAR: From here to the "///end AUTOSAR" is from AUTOSAR without code having /// comment in line.
//% $Id: A0-1-1.cpp 271687 2017-03-23 08:57:35Z piotr.tanski $
#include "autosar.h"/// add header file
#include <array>
#include <cstdint>

using namespace std;/// add using

std::uint8_t fn1(std::uint8_t param) noexcept
{
  std::int32_t x{
    0};  // Non-compliant - DU data flow anomaly; Variable defined,
// but not used
  cout <<endl<< "fn1:x="<< x << endl;
  if (param > 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
std::int32_t fn2() noexcept
{
  std::int8_t x{10U};  // Compliant - variable defined and will be used
  std::int8_t y{20U};  // Compliant - variable defined and will be used
  std::int16_t result = x + y;  // x and y variables used
  x = 0;  // Non-compliant - DU data flow anomaly; Variable defined, but x is
  // not subsequently used and goes out of scope
  y = 0;  // Non-compliant - DU data flow anomaly; Variable defined, but y is
// not subsequently used and goes out of scope
  return result;
}
std::int32_t fn3(std::int32_t param) noexcept
{
  std::int32_t x{param +
                 1};  // Compliant - variable defined, and will be used in
// one of the branches
// However, scope of x variable could be reduced
  if (param > 20)
  {
    return x;
  }
  return 0;
}
std::int32_t fn4(std::int32_t param) noexcept
{
  std::int32_t x{param +
                 1};  // Compliant - variable defined, and will be used in
  // some of the branches
  if (param > 20)
  {
    return x + 1;
  }
  else if (param > 10)
  {
    return x;
  }
  else
  {
    return 0;
  }
}
void fn5() noexcept
{
  std::array<std::int32_t, 100> arr{};
  arr.fill(1);
  constexpr std::uint8_t limit{100U};
  std::int8_t x{0};
  for (std::uint8_t i{0U}; i < limit; ++i)  // Compliant by exception - on the
// final loop, value of i defined will
// not be used
  {
    arr[i] = arr[x];
    ++x;  // Non-compliant - DU data flow anomaly on the final loop, value
    // defined and not used
  }
  cout <<endl<< "fn5:x="<< x<<endl;
}
///end AUTOSAR
int start() {
  uint8_t ui=120;
  int32_t i3= 255*255;
  cout << "fn1("<<ui<< ")=" <<fn1(ui)<<endl;;
  cout << "fn2()="<<fn2()<<endl;;
  cout << "fn3("<<i3<<")="<<fn3(i3)<<endl;
  cout << "fn4("<<i3*ui<<")="<<fn4(i3*ui)<<endl;
  fn5();
  cout<< msg << endl;
  ShutdownOS()  EXIT_SUCCESS;
/// Autosar OS 7.1.2.2 Undefined Behaviour in OSEK OS
/// OS425 If ShutdownOS is called and ShutdownHook() returns then the operating system shall disable all interrupts and enter an endless loop.
}
```
##編纂・実行結果(compile and go)

```shell-session:cpa.sh
$ ../cpa.sh a0-1-1
$ clang++ a0-1-1.cpp -std=c++14 -Wall
fn1(x)=
fn1:x=0

fn2()=30
fn3(65025)=65026
fn4(7803000)=7803002

fn5:x=d
Rule A0-1-1 (required, implementation, automated) A project shall not contain instances of non-volatile variables being given values that are not subsequently used.(1) A0-1-1.cpp.cpp
$ clang++ a0-1-1.cpp -std=c++17 -Wall
fn1(x)=
fn1:x=0

fn2()=30
fn3(65025)=65026
fn4(7803000)=7803002

fn5:x=d
Rule A0-1-1 (required, implementation, automated) A project shall not contain instances of non-volatile variables being given values that are not subsequently used.(1) A0-1-1.cpp.cpp
$ clang++ a0-1-1.cpp -std=c++2a -Wall
fn1(x)=
fn1:x=0

fn2()=30
fn3(65025)=65026
fn4(7803000)=7803002

fn5:x=d
Rule A0-1-1 (required, implementation, automated) A project shall not contain instances of non-volatile variables being given values that are not subsequently used.(1) A0-1-1.cpp.cpp

$ g++-8 a0-1-1.cpp -std=c++14  -Wall
fn1(x)=
fn1:x=0

fn2()=30
fn3(65025)=65026
fn4(7803000)=7803002

fn5:x=d
Rule A0-1-1 (required, implementation, automated) A project shall not contain instances of non-volatile variables being given values that are not subsequently used.(1) A0-1-1.cpp.cpp
$ g++-8 a0-1-1.cpp -std=c++17  -Wall
fn1(x)=
fn1:x=0

fn2()=30
fn3(65025)=65026
fn4(7803000)=7803002

fn5:x=d
Rule A0-1-1 (required, implementation, automated) A project shall not contain instances of non-volatile variables being given values that are not subsequently used.(1) A0-1-1.cpp.cpp
$ g++-8 a0-1-1.cpp -std=c++2a  -Wall
fn1(x)=
fn1:x=0

fn2()=30
fn3(65025)=65026
fn4(7803000)=7803002

fn5:x=d
Rule A0-1-1 (required, implementation, automated) A project shall not contain instances of non-volatile variables being given values that are not subsequently used.(1) A0-1-1.cpp.cpp
```
### Visual Studio 2017

```
>cl A0-1-1.cpp /EHsc
Microsoft(R) C/C++ Optimizing Compiler Version 19.15.26726 for x64
Copyright (C) Microsoft Corporation.  All rights reserved.

A0-1-1.cpp
Microsoft (R) Incremental Linker Version 14.15.26726.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:A0-1-1.exe
A0-1-1.obj

>A0-1-1.exe

fn1:x=0
fn1(x)=
fn2()=30
fn3(65025)=65026
fn4(7803000)=7803002

fn5:x=d
Rule A0-1-1 (required, implementation, automated) A project shall not contain instances of non-volatile variables being given values that are not subsequently used.(1) A0-1-1.cpp

```


###Header file

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
###実行命令

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


#検討事項(agenda)
###1. 自律(freestanding)環境. 接待(hosted)環境

C++N4606 1.4 Implementation compliance p.4

###2. 対応OSの水準、対応通信規約、応用機能による分類
freestanding用の関数、ライブラリ等
###3. C++2014, C++2017, C++202aの比較項目
clang++2014が出力してないのはスクリプトの間違い。
###4. clang++, g++の比較検討項目
現状なし
###5. Visual Studio 2017 /Wall (警告)

visual studio 2017 autosar warning 一部
https://researchmap.jp/jox2zzdpw-1797580/#_1797580

visual studio 2017 autosar warning 全部
https://researchmap.jp/mud6rglqu-45645/?action=multidatabase_action_main_filedownload&download_flag=1&upload_id=177133&metadata_id=25961



#参考文献(reference)

###プログラミング言語教育のXYZ
https://qiita.com/kaizen_nagoya/items/1950c5810fb5c0b07be4
プログラミング言語教育のXYZ(youtube)
https://www.youtube.com/watch?v=He1_tg4px-w&t=486s

###C++N4741 2018
Working Draft, Standard for Programming Language C++
http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/n4741.pdf

C++N4741, 2018 Standard Working Draft on ISO/IEC 14882 sample code compile list
https://qiita.com/kaizen_nagoya/items/3294c014044550896010

###C++N4606 2016
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

#文書履歴
ver 0.10 初稿 20180606
ver 0.11 一覧追記 20180613
ver 0.12 参考文献欄追記 20180616
ver 0.20 Visual Studio 2017追記　20180915
