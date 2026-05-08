#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <memory>
#include <string>

int asm_style() {
  const char* msg = "Hello, World!\n";
  asm volatile(
      "mov %[p], %%rdi\n\t"
      "xor %%eax, %%eax\n\t"  // SysV ABI: Clean AL before calling printf
                              // (mutable parameter function)
      "call printf@PLT\n\t"
      :
      : [p] "r"(msg)
      : "rdi", "rax", "rcx", "rdx", "rsi", "r8", "r9", "r10", "r11", "memory");
  return 0;
}

int c_style() {
  printf("%s\n", "Hello, World!");
  // printf is a C function, it can be called from C++
  return 0;
}

int cpp_style() {
  //         Smart Pointer       Templates
  //              |                  |
  auto str = std::make_unique<std::string>("Hello, World!");
  std::cout << *str << std::endl;
  //   |                     |
  //  Stream         Operator Overloading

  return 0;
}

int main(int argc, char* argv[]) {
  // All results are the same: Hello, World!
  asm_style();
  c_style();
  cpp_style();
  return 0;
}
