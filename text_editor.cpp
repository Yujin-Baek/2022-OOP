#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

class Command {
  private:
    int start;
    int end;
    vector<char> text;
    static Command* command;

    Command(int s = 0, int e = 0) {
      start = s;
      end = e;
    }
  public:
    static Command *get_instance() {
      if(!command) command = new Command;
      return command;
    }

    void set_index(int start, int end) {
      this->start = start;
      this->end = end;
    }

    int get_sindex() {
      return this->start;
    }

    int get_eindex() {
      return this->end;
    }

    void read_file() {
      ifstream rfile ("test.txt");
      int c;
      while((c=rfile.get())!=EOF)
      text.push_back((char)c);
      rfile.close();
      print();
    }

    void save() {
      ofstream wfile ("test.txt");
      string s_text (text.begin(), text.end());
      if (wfile.fail()) {
		    cerr << "Error!" << endl;
	    }
	    wfile << s_text << std::endl;

      wfile.close();
    }

    void print() {
      int lineCount = this->start/75 + 1;

      for (int i=this->start; i<this->start+20*75; i+=75) {
        if(i+75 > text.size()-1) {
          if(lineCount<10) cout << " " << lineCount++ << "| ";
          else cout << lineCount++ << "| ";
          for (int j=i; j<text.size(); j++) cout << text[j];
          break;
        }
        else {
          if(lineCount<10) cout << " " << lineCount++ << "| ";
          else cout << lineCount++ << "| ";

          for (int j=0; j<75; j++) cout << text[i+j];
          cout << endl;
        }
      }

    }

    void previous_print() {
      if(this->start == 0) cout << "첫 페이지입니다." << endl;
      else {
        if(this->start-75*20 < 0) {
          int left_line = ceil((double)this->start/75);
          set_index(0, this->end-left_line*75);
          print();
        } else {
          set_index(this->start-75*20, this->end-75*20);
          print();
        }
      }
    }

    void next_print() {
      double max = text.size();
      if(this->end == max) cout << "마지막 페이지입니다." << endl;
      else {
        if(this->end+75*20 > max) {
          int left_line = ceil((max - (double)this->end)/75);
          set_index(this->start+left_line*75, max);
          print();
        } else {
          set_index(this->start+75*20, this->end+75*20);
          print();
        }
      }
    }

    void insert(int line, int index, string insert_string) {
      vector<char> insert_char(insert_string.begin(), insert_string.end());
      for (int i=0; i<insert_char.size(); i++) text.insert(text.begin()+(line-1)*75+index+i, insert_char[i]);
      print();
    }

    void erase(int line, int index, int erase_length) {
      text.erase(text.begin()+(line-1)*75+index, text.begin()+(line-1)*75+index+erase_length);
      print();
    }

    void search(string search_string) {
      string s_text (text.begin(), text.end());
      int find_index = s_text.find(search_string);
      double max = text.size()-1;
      if(find_index==string::npos) cout << "해당 문자열이 파일에 존재하지 않습니다." << endl;
      else {
        int old_start = this->start;
        int old_end = this->end;
        set_index(find_index, find_index+75*20);
        print();
        set_index(old_start, old_end);
      }
    }

    void change(string old_string, string new_string) {
      string s_text (text.begin(), text.end());
      int find_index = s_text.find(old_string);
      if(find_index==string::npos) cout << "바꿀 문자열이 파일에 존재하지 않습니다." << endl;
      else {
        s_text = regex_replace(s_text, regex(old_string), new_string);
        text.clear();
        copy(s_text.begin(), s_text.end(), back_inserter(text));
        print();
      }
    }
};

Command* Command::command = 0;

int main() {
  Command::get_instance()->set_index(0, 75*20);
  Command::get_instance()->read_file();

  while(true) {
    for(int i=0; i<80; i++) cout << "-";
    cout << endl;
    cout << "n:다음 페이지, p:이전 페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후종료" << endl;
    for(int i=0; i<80; i++) cout << "-";
    cout << endl;
    cout << "입력:";
    string input;
    cin >> input;

    for(int i=0; i<80; i++) cout << "-";
    cout << endl;

    vector<char> in(input.begin(), input.end());

    int instruction = in[0];

    if(instruction=='t') {
      Command::get_instance()->save();
      cout << "저장 후 종료합니다." << endl;
      for(int i=0; i<80; i++) cout << "-";
      break;
    }

    switch (instruction) {
      case 'n':
        Command::get_instance()->next_print();
        break;
      case 'p':
        Command::get_instance()->previous_print();
        break;
      case 'i':
        {
        string str (in.begin()+2, in.end()-1);

        int cnt = 0;
        for(int i=0;i<str.length();i++)
          if(str[i]==',') cnt++;
        
        if(cnt!=2) {
          cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
          break;
        }

        vector<string> split_str;
        for(int i=0; i<2; i++) {
          int split_index = str.find(',');
          split_str.push_back(str.substr(0, split_index));
          str = str.substr(split_index+1, str.length()-1);
        }
        split_str.push_back(str);

        bool isDigit = (atoi(split_str[0].c_str())!=0 || split_str[0] == "0" ) && (atoi(split_str[1].c_str())!=0 || split_str[1] == "0" );
        bool isinRange = (Command::get_instance()->get_sindex()/75<stoi(split_str[0])) && (stoi(split_str[0]) <= Command::get_instance()->get_sindex()/75+20) && (0<=stoi(split_str[1])) && (stoi(split_str[1])<=75);

        if(isDigit && isinRange) {
          Command::get_instance()->insert(stoi(split_str[0]), stoi(split_str[1]), split_str[2]);
        } else {
          cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
        }
        break;
        }
      case 'd':
        {
        string str (in.begin()+2, in.end()-1);

        int cnt = 0;
        for(int i=0;i<str.length();i++)
          if(str[i]==',') cnt++;
        
        if(cnt!=2) {
          cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
          break;
        }

        vector<string> split_str;
        for(int i=0; i<2; i++) {
          int split_index = str.find(',');
          split_str.push_back(str.substr(0, split_index));
          str = str.substr(split_index+1, str.length()-1);
        }
        split_str.push_back(str);

        bool isDigit = (atoi(split_str[0].c_str())!=0 || split_str[0] == "0" ) && (atoi(split_str[1].c_str())!=0 || split_str[1] == "0" )  && (atoi(split_str[2].c_str())!=0 || split_str[2] == "0" );
        bool isinRange = (Command::get_instance()->get_sindex()/75<stoi(split_str[0])) && (stoi(split_str[0]) <= Command::get_instance()->get_sindex()/75+20) && (0<=stoi(split_str[1])) && (stoi(split_str[1])<=75) && (0<=stoi(split_str[2])) && (stoi(split_str[2])<=75) && (stoi(split_str[1])+stoi(split_str[2])<=75);

        if(isDigit && isinRange) {
          Command::get_instance()->erase(stoi(split_str[0]), stoi(split_str[1]), stoi(split_str[2]));
        } else {
          cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
        }
        break;
        }
      case 's':
        {
          string str (in.begin()+2, in.end()-1);
          if(str.find(',')!=string::npos) cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
          else Command::get_instance()->search(str);
          break;
        }
      case 'c':
        {
          string str (in.begin()+2, in.end()-1);

          int cnt = 0;
          for(int i=0;i<str.length();i++)
            if(str[i]==',') cnt++;
        
          if(cnt!=1) {
            cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
            break;
          }

          vector<string> split_str;

          int split_index = str.find(',');
          split_str.push_back(str.substr(0, split_index));
          str = str.substr(split_index+1, str.length()-1);
          split_str.push_back(str);
          Command::get_instance()->change(split_str[0], split_str[1]);
          break;
        }
      default:
        cout << "존재하지 않는 명령어입니다. 다시 입력해주세요." << endl;
        break;
    }
  }
}