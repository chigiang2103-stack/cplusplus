#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string getFileName(string path) {
    size_t found = path.find_last_of("/");
    return (found == string::npos) ? path : path.substr(found + 1);
}

int main(int argc, char* argv[]) {
    // argc : số tham số 
    // argv : mảng chứa tham số
    if (argc < 5) {
        cout << "USING : ./MYCOPYFILE -s <source> -d <destination>" << endl;
        return 1;
    }

    string sourcePath, destDir;
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-s") sourcePath = argv[i + 1];
        if (string(argv[i]) == "-d") destDir = argv[i + 1];
    }

    string fileName = getFileName(sourcePath);
    string fullDestPath = destDir + "/" + fileName;

    ifstream src(sourcePath, ios::binary);
    if (!src) {
        cout << "Lỗi không thể mở file" << endl;
        return 1;
    }

    ofstream dst(fullDestPath, ios::binary);
    if (!dst) {
        cout << "lỗi không thể tạo file" << endl;
        return 1;
    }

    char buffer[4096]; 
    while (src.read(buffer, sizeof(buffer))) {
        dst.write(buffer, src.gcount());
    }
    dst.write(buffer, src.gcount()); 

    cout << "File đã tạo thành công" << fullDestPath << endl;

    src.close();
    dst.close();
    return 0;
}