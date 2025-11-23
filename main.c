#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  // 檢查命令列參數是否正確
  if(argc != 3){
    printf("使用方式: %s <輸入檔案> <輸出檔案>\n", argv[0]);
    return 1;
  }
  
  // 開啟輸入檔案
  FILE *input_file = fopen(argv[1], "r");
  if(input_file == NULL){
    printf("錯誤: 無法開啟輸入檔案 '%s'\n", argv[1]);
    return 1;
  }
  
  // 開啟輸出檔案
  FILE *output_file = fopen(argv[2], "w");
  if(output_file == NULL){
    printf("錯誤: 無法開啟輸出檔案 '%s'\n", argv[2]);
    fclose(input_file);
    return 1;
  }
  
  // 逐字元讀取並寫入
  int ch;
  while((ch = fgetc(input_file)) != EOF){
    fputc(ch, output_file);
  }
  
  // 關閉檔案
  fclose(input_file);
  fclose(output_file);
  
  printf("成功將 '%s' 複製到 '%s'\n", argv[1], argv[2]);
  return 0;
}
