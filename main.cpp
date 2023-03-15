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
        string column;
        vector<string> rows;

        while (getline(file, line)) {
            rows.clear();

            stringstream line_stream(line);

            while (getline(line_stream, column, delimiter)) {
                rows.push_back(column);
            }
            content.push_back(rows);
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
