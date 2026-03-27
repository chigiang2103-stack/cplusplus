#include <bits/stdc++.h>
using namespace std;

// Lấy tên file gốc: film.mkv
string getOriginalFileName(const string& part01Path) {
    size_t pos = part01Path.rfind(".part");
    if (pos == string::npos) return "";
    return part01Path.substr(
        part01Path.find_last_of("/\\") + 1,
        pos - part01Path.find_last_of("/\\") - 1
    );
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cout << "Su dung: MYMERGEFILE -s <path_of_part01> -d <path_of_destination>\n";
        return 1;
    }

    string part01Path = argv[2];
    string destDir = argv[4];

    ifstream test(part01Path, ios::binary);
    if (!test) {
        cout << "Lỗi: not found file part01!\n";
        return 1;
    }
    test.close();

    string originalName = getOriginalFileName(part01Path);
    string outputPath = destDir + "/" + originalName;

    ofstream dst(outputPath, ios::binary);
    if (!dst) {
        cout << "Lỗi không thể tạo file đích!\n";
        return 1;
    }

    string partPrefix = part01Path.substr(0, part01Path.size() - 2);

    int partNum = 1;
    const int BUF_SIZE = 1024 * 1024;
    char buffer[BUF_SIZE];

    while (true) {
        stringstream ss;
        ss << partPrefix << setw(2) << setfill('0') << partNum;
        string currentPart = ss.str();

        ifstream src(currentPart, ios::binary);
        if (!src) {
            cout << "Dã gộp xong " << partNum - 1 << " phần\n";
            break;
        }


        while (src.read(buffer, BUF_SIZE) || src.gcount()) {
            dst.write(buffer, src.gcount());
        }

        src.close();
        partNum++;
    }

    dst.close();

    return 0;
}
