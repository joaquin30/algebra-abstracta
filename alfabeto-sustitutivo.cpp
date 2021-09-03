#include <bits/stdc++.h>
using namespace std;

int total;
array<char, 26> abc;
array<bool, 26> used;
vector<pair<char, int>> dict_letters;
vector<pair<string, int>> dict_words;
string text;
const char *red= "\033[0;31m", *nocolor = "\033[0m"; //codigos ANSI

vector<string> split_space(const string& str) {
    istringstream input(str);
    string tmp;
    vector<string> ans;
    while (input>>tmp) ans.push_back(tmp);
    return ans;
}

bool fset(const string& tmp) {
    auto cmd = split_space(tmp);
    if (cmd.size() != 3) return false;
    if (cmd[0] != "set") return false;
    if (cmd[1].size() != 1 || !islower(cmd[1][0])) return false;
    if (cmd[2].size() != 1 || !islower(cmd[2][0])) return false;
    int a = cmd[1][0]-'a', b = cmd[2][0]-'a';
    abc[a] = b+'a';
    used[a] = true;
    return true;
}

void get_letters() {
    for (auto i : dict_letters) {
        if (used[i.first-'a']) cout<<red;
        cout<<abc[i.first-'a'];
        if (used[i.first-'a']) cout<<nocolor;
        cout<<"\t"<<i.second<<"\t"<<(float)(i.second)/total*100<<"%\n";
    }
}

void get_words() {
    for (auto i : dict_words) {
        for (auto j : i.first) {
            if (used[j-'a']) cout<<red;
            cout<<abc[j-'a'];
            if (used[j-'a']) cout<<nocolor;
        }
        cout<<"\t"<<i.second<<"\n";
    }
}

void get_text() {
    for (auto i : text) {
        if (!isalpha(i)) cout<<i;
        else {
            if (used[i-'a']) cout<<red;
            cout<<abc[i-'a'];
            if (used[i-'a']) cout<<nocolor;
        }
    }
    cout<<"\n";
}

void get_alphabet() {
    for (int i=0; i<26; ++i) {
        cout<<(char)(i+'a')<<"\t";
        if (used[i]) cout<<red;
        cout<<abc[i]<<"\n";
        if (used[i]) cout<<nocolor;
    }
}

void test() {
    for (auto i : used) {
        if (!i) {
            cout<<R"(Faltan letras para completar el alfabeto sustitutivo
Usa el comando "get alphabet" para más información
)";
            return;
        }
    }
    
    map<char, int> tmp;
    for (auto i : abc) tmp[i]++;
    if (tmp.size() != 26)  {
        cout<<"La(s) letra(s) "<<red;

        for (auto j : tmp) {
            if (j.second>1) cout<<j.first<<" ";
        }
       
        cout<<nocolor<<"se repiten\nUsa el comando \"get alphabet\" para más información\n";
        return;
    }

    cout<<"El alfabeto sustitutivo pasó la prueba\n";
}

void help() {
    cout<<R"(get <opción>
    text      Ver el texto
    letters   Ver la tabla de frecuencias de las letras
    words     Ver la tabla de frecuencias de las palabras de 3 letras o menos
    alphabet  Ver el alfabeto sustitutivo
set <a> <b>   Reemplazar en el texto las letras <a> con la letra <b>
test          Prueba si el afabeto sustitutivo esta completo
help          Ver este mensaje
exit          Salir del programa
)";
}

template<class T>
bool fsort(pair<T, int> p1, pair<T, int> p2) {
    return p1.second > p2.second;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cout<<setprecision(2);

    if (argc != 2) {
        cout<<"Es necesario un nombre de archivo para descifrar\n";
        return 1;
    }

    ifstream input(argv[1]);

    if (!input) {
        cout<<"Error al abrir el archivo\n";
        return 1;
    }

    cout<<"Descifrador de alfabeto sustitutivo\nArchivo abierto: "
        <<argv[1]<<"\nEscriba \"help\" para ver los comandos\n";
    for (char i=0; i<27; ++i) abc[i] = i+'a';
    text.assign(istreambuf_iterator<char>(input), istreambuf_iterator<char>());
    map<char, int> map_letters;
    auto words = split_space(text);
    map<string, int> map_words;

    for (auto& i : text) {
        if (!isalpha(i)) continue;
        if (isupper(i)) i = tolower(i);
        map_letters[i]++;
        total++;
    }

    for (auto& i : words) {
        if (i.size() > 3) continue;
        map_words[i]++;
    }

    for (auto i : map_letters) dict_letters.push_back(i);
    for (auto& i : map_words) dict_words.push_back(i);
    sort(dict_letters.begin(), dict_letters.end(), fsort<char>);
    sort(dict_words.begin(), dict_words.end(), fsort<string>);

    while (true) {
        cout<<">> ";
        string cmd;
        getline(cin, cmd);
        if (cmd == "exit") break;
        else if (cmd == "help") help();
        else if (cmd == "test") test();
        else if (cmd == "get text") get_text();
        else if (cmd == "get words") get_words();
        else if (cmd == "get letters") get_letters();
        else if (cmd == "get alphabet") get_alphabet();
        else if (!fset(cmd)) cout<<"No se entendió el comando\n";
        cout<<flush;
    }

    return 0;
}