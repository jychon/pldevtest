#include <iostream>
#include <chrono>
#include <thread>
#include<cstdlib>
#include <string>
#include <fstream>
using namespace std;

// using hour = std::chrono::duration<double, ratio<60>>;

void putTimeinFiles(string &fileName)
{
    ofstream file(fileName, std::ofstream::out);
    auto current_clock = chrono::high_resolution_clock::now();
    chrono::hours sinceEpoch = std::chrono::duration_cast<chrono::hours>(current_clock.time_since_epoch());
    file << sinceEpoch.count();
    file.close();
}

double timeSinceCreation(string &filename)
{
    ifstream file(filename, std::ifstream::in);
    if (file.is_open())
    {
        double inTime;
        string inLine;
        getline (file, inLine);
        inTime = stoi (inLine);
        // hour orgTime = static_cast<hour>(inTime);
        auto cur_clock = chrono::high_resolution_clock::now();
        chrono::hours cur_time = chrono::duration_cast<chrono::hours>(cur_clock.time_since_epoch());
        return cur_time.count() - inTime;
    }
    cout << "Cannot find file\n";
    return -1;
}

int main(){
    string file_name = "time created.txt";
    putTimeinFiles(file_name);
    this_thread::sleep_for(chrono::duration<unsigned int>(2));
    cout << "It has been " << timeSinceCreation(file_name) << " hours since this file was created" << endl;
}