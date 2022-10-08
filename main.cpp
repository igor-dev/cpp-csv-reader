#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::fstream;
using std::ios;
using std::string;
using std::stringstream;
using std::vector;

void print(const vector<vector<string>>& content);

int main()
{
    const string file_path("AAL.CSV");
    const auto delimiter{','};

    vector<vector<string>> content;

    if (fstream file(file_path, ios::in); file.is_open()) {
        string line;
        string word;
        vector<string> row;

        while (getline(file, line)) {
            row.clear();

            stringstream line_stream(line);

            while (getline(line_stream, word, delimiter)) {
                row.push_back(word);
            }
            content.push_back(row);
        }
    } else {
        cout << "Could not open the file\n";
    }

    print(content);

    return 0;
}

void print(const vector<vector<string>>& content)
{
    for (const auto& row: content) {
        for (const auto& item: row) {
            cout << item << " ";
        }
        cout << "\n";
    }
    cout << "\n" << content.size() << " rows\n";
}
