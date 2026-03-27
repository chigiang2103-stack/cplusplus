#include <bits/stdc++.h>

using namespace std;

string getFileName(string path) {
    size_t found = path.find_last_of("/");
    return (found == string::npos) ? path : path.substr(found + 1);
}

void splitFile(string srcPath, string destDir, long long partSize) {
    ifstream src(srcPath, ios::binary | ios::ate); 
    if (!src) {
        cout << "Lỗi mở file!" << endl;
        return;
    }

    long long totalSize = src.tellg(); 
    src.seekg(0, ios::beg);         

    string baseName = getFileName(srcPath);
    int partNum = 1;
    char* buffer = new char[1024 * 1024];
    while (src.tellg() < totalSize && !src.eof()) {
    
        stringstream ss;
        ss << destDir << "/" << baseName << ".part" << setfill('0') << setw(2) << partNum;
        
        ofstream dst(ss.str(), ios::binary);
        long long written = 0;
        
        while (written < partSize && !src.eof()) {
            long long toRead = min((long long)1024 * 1024, partSize - written);
            src.read(buffer, toRead);
            long long bytesRead = src.gcount();
            if (bytesRead == 0) break;
            
            dst.write(buffer, bytesRead);
            written += bytesRead;
        }
        dst.close();
        if (written > 0) partNum++;
        else break;
    }

    delete[] buffer;
    src.close();
    cout << "đã chia file thành " << partNum - 1 << " phần" << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 7) {
        cout << "Su dung:\n  -numpart x\n  -sizeapart y" << endl;
        return 1;
    }

    string srcPath, destDir, mode;
    long long value = 0;

    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-s") srcPath = argv[++i];
        else if (arg == "-d") destDir = argv[++i];
        else if (arg == "-numpart" || arg == "-sizeapart") {
            mode = arg;
            value = stoll(argv[++i]);
        }
    }

    if (mode == "-numpart") {
        ifstream temp(srcPath, ios::binary | ios::ate);
        long long total = temp.tellg();
        temp.close();
        splitFile(srcPath, destDir, ceil((double)total / value));
    } else {
        splitFile(srcPath, destDir, value);
    }

    return 0;
}