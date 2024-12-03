# CMake generated Testfile for 
# Source directory: C:/Users/Lenovo/Desktop/cppaliens/alieninvasion
# Build directory: C:/Users/Lenovo/Desktop/cppaliens/alieninvasion/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(RunTests "C:/Users/Lenovo/Desktop/cppaliens/alieninvasion/build/Debug/tests.exe")
  set_tests_properties(RunTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Lenovo/Desktop/cppaliens/alieninvasion/CMakeLists.txt;44;add_test;C:/Users/Lenovo/Desktop/cppaliens/alieninvasion/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(RunTests "C:/Users/Lenovo/Desktop/cppaliens/alieninvasion/build/Release/tests.exe")
  set_tests_properties(RunTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Lenovo/Desktop/cppaliens/alieninvasion/CMakeLists.txt;44;add_test;C:/Users/Lenovo/Desktop/cppaliens/alieninvasion/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(RunTests "C:/Users/Lenovo/Desktop/cppaliens/alieninvasion/build/MinSizeRel/tests.exe")
  set_tests_properties(RunTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Lenovo/Desktop/cppaliens/alieninvasion/CMakeLists.txt;44;add_test;C:/Users/Lenovo/Desktop/cppaliens/alieninvasion/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(RunTests "C:/Users/Lenovo/Desktop/cppaliens/alieninvasion/build/RelWithDebInfo/tests.exe")
  set_tests_properties(RunTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Lenovo/Desktop/cppaliens/alieninvasion/CMakeLists.txt;44;add_test;C:/Users/Lenovo/Desktop/cppaliens/alieninvasion/CMakeLists.txt;0;")
else()
  add_test(RunTests NOT_AVAILABLE)
endif()
