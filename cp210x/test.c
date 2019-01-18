#include <windows.h>
#include <stdio.h>
#include "SiUSBXp.h"

int main(int argc, char* argv[]) {
  DWORD ndev;
  SI_GetNumDevices(&ndev);
  printf("You've got %ld devices connected\n", ndev);
  return 0;
}
