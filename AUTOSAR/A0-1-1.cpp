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
