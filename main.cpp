#include<stdio.h>

int main(int argc, char** argv) {

    FILE* file_goc = fopen(argv[1], "ab+");//Doc file khi keo vao
    FILE* file_mod = fopen(argv[2], "ab+");//Doc file khi keo vao
    char buffer[32768] = { 0x00 };//Ma 00
    fseek(file_goc, 0, SEEK_END);//Dich chuyen con tro den cuoi file
    fseek(file_mod, 0, SEEK_END);//Dich chuyen con tro den cuoi file
    int sizeFileGoc = ftell(file_goc);//Kich thuoc file mod = Vi tri hien tai cua con tro
    int sizeFileMod = ftell(file_mod);//Kich thuoc file mod = Vi tri hien tai cua con tro

    for (int i = 0; i < (sizeFileGoc - sizeFileMod) / 32768; i++)
        fwrite(buffer, 32768, 1, file_mod);

    fseek(file_mod, 0, SEEK_END);//Dich chuyen con tro den cuoi file
    sizeFileMod = ftell(file_mod);//Kich thuoc file mod = Vi tri hien tai cua con tro

    fwrite(buffer, 1, (sizeFileGoc - sizeFileMod), file_mod);

    fclose(file_goc);
    fclose(file_mod);
}
