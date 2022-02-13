#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>

#define L 40
#define C 40
#define Bl 1590

using namespace std;

void menu(char& opcao1);
void nivel(char& opcao2);
void escolha_final(char& opcao1);
void exibe_melhores_tempos(char j1[], int& t1, char j2[], int& t2, char j3[], int& t3, char dificuldade[]);
void salva_tempo(char j1[], int& t1, char j2[], int& t2, char j3[], int& t3, char nome[], int& Tf, char dificuldade[]);

bool jogo(int linha, int coluna, int B, int opcao1, int& Tf);
char troca_letra(char& letra);
void iniciar(char gabarito[L][C], char campo[L][C], int bomba_l[Bl], int bomba_c[Bl], int linha, int coluna, int B);
void gera_gabarito(char gabarito[L][C], int bomba_l[Bl], int bomba_c[Bl], int linha, int coluna, int B);
void exibe_campo(char campo[L][C], int linha, int coluna, int Tf);
void marca_local(char campo[L][C], char letra, int coord_l, int coord_c, int& minas, int linha, int coluna, int Tf);
void mostra_local(char gabarito[L][C], char campo[L][C], int coord_l, int coord_c, int& checa_campo);
int vizinhanca(int coord_l, int coord_c, int bomba_l[Bl], int bomba_c[Bl], int B);
bool verifica_bomba(int coord_l, int coord_c, int bomba_l[Bl], int bomba_c[Bl], int B);
void revela_vazio(char gabarito[L][C], char campo[L][C], int coord_l, int coord_c, int bomba_l[Bl], int bomba_c[Bl], int& checa_campo, int linha, int coluna);
void fim_de_jogo(char gabarito[L][C], char campo[L][C], int linha, int coluna);

int main(){

    char opcao1;
    menu(opcao1);

    while(opcao1 != 's'){
        char opcao2;
        opcao2 = troca_letra(opcao2);

        char j1[20]={}, j2[20]={}, j3[20]={}, nome[20]={};
        int t1, t2, t3;
        char iniciante[]="iniciante.txt", intermediario[]="intermediario.txt";

        if(opcao1 == 'n'){
            nivel(opcao2);
            int linha, coluna, B, Tf;
            bool teste;

            if(opcao2 == 'e'){
                linha = 8, coluna = 8, B = 10;
                teste = jogo(linha, coluna, B, opcao1, Tf);

                if(teste){
                    salva_tempo(j1, t1, j2, t2, j3, t3, nome, Tf, iniciante);
                }

                escolha_final(opcao1);
            }
            else if(opcao2 == 'm'){
                linha = 16, coluna = 16, B = 40;
                teste = jogo(linha, coluna, B, opcao1, Tf);

                if(teste){
                    salva_tempo(j1, t1, j2, t2, j3, t3, nome, Tf, intermediario);
                }

                escolha_final(opcao1);
            }
            else if(opcao2 == 'p'){
                system("cls || clear");
                cout << endl << endl << endl;

                cout << "Digite a quantidade de linhas: ";
                cin >> linha;
                while(linha>40){
                    cout << "Digite novamente: ";
                    cin >> linha;
                }

                cout << "Digite a quantidade de colunas: ";
                cin >> coluna;
                while(coluna>40){
                    cout << "Digite novamente: ";
                    cin >> coluna;
                }

                cout << "Digite a quantidade de bombas: ";
                cin >> B;
                if(((linha*coluna)-10)>0){
                    while(B>((linha*coluna)-10) || B==0){
                        cout << "Digite novamente: ";
                        cin >> B;
                    }
                }
                else{
                    while(B>linha*coluna || B==0){
                        cout << "Digite novamente: ";
                        cin >> B;
                    }
                }

                jogo(linha, coluna, B, opcao1, Tf);

                escolha_final(opcao1);
            }
            else{
                menu(opcao1);
            }
        }
        else if(opcao1 == 'm'){
            system("cls || clear");
            cout << endl << "Melhores tempos: " << endl << endl;

            cout << "Iniciante: " << endl;
            exibe_melhores_tempos(j1, t1, j2, t2, j3, t3, iniciante);

            cout << endl << "Intermediario: " << endl;
            exibe_melhores_tempos(j1, t1, j2, t2, j3, t3, intermediario);

            cout << endl << endl;
            cout << "Aperte: " << endl << "V - Para voltar"<< endl << endl;
            cin >> opcao2;
            menu(opcao1);
        }
    }

    system("cls || clear");
    cout << endl << "Ate logo o/" << endl;

}

void menu(char& opcao1){
    system("cls || clear");

    cout << "             Campo Minado";

    cout << endl << endl << endl;
    cout << "Digite o que voce quer: ";
    cout << endl << "N - Novo jogo";
    cout << endl << "M - Melhores tempos";
    cout << endl << "S - Sair";
    cout << endl << endl << endl;
    cin >> opcao1;

    opcao1 = troca_letra(opcao1);

    while(opcao1 != 'n' && opcao1 != 'm' && opcao1 != 's'){
        cout << "Digite novamente: ";
        cin >> opcao1;
    }
}

void nivel(char& opcao2){
    system("cls || clear");

    cout << endl << "Novo Jogo" << endl << endl;

    cout << "Qual e o nivel?";
    cout << endl << "E - Iniciante";
    cout << endl << "M - Intermediario";
    cout << endl << "P - Personalizado";
    cout << endl << "V - Voltar";
    cout << endl << endl << endl;
    cin >> opcao2;

    opcao2 = troca_letra(opcao2);

    while(opcao2 != 'e' && opcao2 != 'm' && opcao2 != 'p' && opcao2 != 'v'){
        cout << "Digite novamente: ";
        cin >> opcao2;
    }
}

void escolha_final(char& opcao1){
    cout << endl << "O que deseja fazer?" << endl << "S - Para sair" << endl << "N - Para jogar novamente" << endl << "M - Para ver os melhores tempos" << endl << endl;
    cin >> opcao1;
    opcao1 = troca_letra(opcao1);

    while(opcao1 != 'n' && opcao1 != 'm' && opcao1 != 's'){
        cout << "Digite novamente: ";
        cin >> opcao1;
        opcao1 = troca_letra(opcao1);
    }
}

void exibe_melhores_tempos(char j1[], int& t1, char j2[], int& t2, char j3[], int& t3, char dificuldade[]){
    ifstream l_t(dificuldade);

    while( !l_t.eof() ) {
        l_t >> j1;
        l_t >> t1;
        l_t >> j2;
        l_t >> t2;
        l_t >> j3;
        l_t >> t3;
    }

    l_t.close();

    cout << j1 << ": " << t1 << " segundos" << endl;
    cout << j2 << ": " << t2 << " segundos" << endl;
    cout << j3 << ": " << t3 << " segundos" << endl;
}

void salva_tempo(char j1[], int& t1, char j2[], int& t2, char j3[], int& t3, char nome[], int& Tf, char dificuldade[]){
    ifstream l_t(dificuldade);

    while( !l_t.eof() ) {
        l_t >> j1;
        l_t >> t1;
        l_t >> j2;
        l_t >> t2;
        l_t >> j3;
        l_t >> t3;
    }

    if(Tf < t3) {
        cout << "Digite seu nome: ";
        cin >> nome;
        cout << endl;

        if(Tf < t1) {
            strcpy(j3, j2);
            t3 = t2;
            strcpy(j2, j1);
            t2 = t1;
            strcpy(j1, nome);
            t1 = Tf;
        }
        else if(Tf < t2) {
            strcpy(j3, j2);
            t3 = t2;
            strcpy(j2, nome);
            t2 = Tf;
        } else {
            strcpy(j3, nome);
            t3 = Tf;
        }
    }

    ofstream e_t(dificuldade);

    e_t << j1 << endl;
    e_t << t1 << endl;
    e_t << j2 << endl;
    e_t << t2 << endl;
    e_t << j3 << endl;
    e_t << t3;

    e_t.close();
    l_t.close();
}

bool jogo(int linha, int coluna, int B, int opcao1, int& Tf){
    system("cls || clear");
    srand(time(NULL));

    int Ti=0;

    char gabarito[L][C], campo[L][C];

    int bomba_l[Bl]={}, bomba_c[Bl]={};

    bool tem_bomba;

    char letra;
    int minas=B, coord_l, coord_c;
    int checa_campo=((linha*coluna)-B);

    iniciar(gabarito, campo, bomba_l, bomba_c, linha, coluna, B);

    Ti = time(NULL);

    do{
        Tf = time(NULL) - Ti;

        exibe_campo(campo, linha, coluna, Tf);

        cout << Tf << " segundos." << endl << endl;

        cout << "Minas a marcar: " << minas << endl;
        cout << "D --> Descobrir quadrado" << endl;
        cout << "M --> Marcar mina" << endl;
        cout << "T --> Talvez mina" << endl;
        cout << "L --> Limpar marcacao" << endl;
        cout << "S --> Sair" << endl;
        cout << "Digite a opcao seguida das coordenadas (ex.: d 1 1): ";
        cin >> letra;

        letra = troca_letra(letra);

        if(letra == 's'){
            system("cls || clear");
            break;
        }

        while(letra != 'd' && letra != 'm' && letra != 't' && letra != 'l'){
            cout << "Digite uma letra: ";
            cin >> letra;
            letra = troca_letra(letra);
        }

        cout << "Digite as coordenadas: ";
        cin >> coord_l >> coord_c;

        while(coord_l < 1 || coord_l > linha){
            cout << "Digite a coordenadas de linha: ";
            cin >> coord_l;
        }

        while(coord_c < 1 || coord_c > coluna){
            cout << "Digite a coordenadas de coluna: ";
            cin >> coord_c;
        }

        tem_bomba = verifica_bomba(coord_l-1, coord_c-1, bomba_l, bomba_c, B);

        if(letra == 'd') {
            if(tem_bomba){

                system("cls || clear");
                fim_de_jogo(gabarito,campo, linha, coluna);
                exibe_campo(campo, linha, coluna, Tf);

                Tf = time(NULL) - Ti;

                cout << "Voce perdeu" << endl << endl;
                cout << "Seu tempo: " << Tf << " segundos." << endl << endl;
                return false;
                break;

            } else if(campo[coord_l-1][coord_c-1] != 'M') {
                mostra_local(gabarito, campo, coord_l-1, coord_c-1, checa_campo);

                if(campo[coord_l-1][coord_c-1] == '_') {
                    revela_vazio(gabarito, campo, coord_l-1, coord_c-1, bomba_l, bomba_c, checa_campo, linha, coluna);
                }

                if(checa_campo == 0) {
                    system("cls || clear");
                    exibe_campo(campo, linha, coluna, Tf);

                    Tf = time(NULL) - Ti;

                    cout << "Voce ganhou!" << endl << endl;
                    cout << "Seu tempo: " << Tf << " segundos." << endl << endl;
                    return true;
                    break;
                }
            }

        } else {
            marca_local(campo, letra, coord_l, coord_c, minas, linha, coluna, Tf);
        }
        system("cls || clear");

    } while(1);

    return false;
}

char troca_letra(char& letra){
    if(letra>='A' && letra<='Z'){
        int l = letra;
        letra = l + 32;
    }
    return letra;
}

void iniciar(char gabarito[L][C], char campo[L][C], int bomba_l[], int bomba_c[], int linha, int coluna, int B)
{
    for(int i=0; i<linha; i++) {
        for(int j=0; j<coluna; j++) {
            campo[i][j] = '.';
        }
    }

    gera_gabarito(gabarito, bomba_l, bomba_c, linha, coluna, B);
}

void gera_gabarito(char gabarito[L][C], int bomba_l[], int bomba_c[], int linha, int coluna, int B)
{
    for(int i=0; i<linha; i++) {
        for(int j=0; j<coluna; j++) {
            gabarito[i][j] = '_';
        }
    }

    for(int k=0; k<B; k++) {
        int l = rand()%linha;
        int c = rand()%coluna;

        if(gabarito[l][c]=='_'){
            gabarito[l][c] = '*';
            bomba_l[k] = l;
            bomba_c[k] = c;
        }
        else {
            k--;
        }
    }

    int viz;
    for(int c_l=0; c_l<linha ; c_l++) {
        for(int c_c=0; c_c<coluna; c_c++) {
            viz = vizinhanca(c_l, c_c, bomba_l, bomba_c, B);
            if(viz != 0 && gabarito[c_l][c_c] != '*'){
                gabarito[c_l][c_c] = viz + 48;
            }
        }
    }
}

void exibe_campo(char campo[L][C], int linha, int coluna, int Tf)
{
    cout << "    ";
        for(int k=1; k<(coluna+1); k++) {
            if(k<10){
                cout << k << "  ";
            } else {
                cout << k << " ";
            }
        }

        cout << endl;

        for(int i=0; i<linha; i++) {
            if(i<9){
                cout << " " << i+1 << "  ";
                for(int j=0; j<coluna; j++) {
                cout << campo[i][j] << "  ";
                }
            } else {
                cout << i+1 << "  ";
                for(int j=0; j<coluna; j++) {
                cout << campo[i][j] << "  ";
                }
            }
            cout << endl;
        }

    cout << endl;
}

void marca_local(char campo[L][C], char letra, int coord_l, int coord_c, int& minas, int linha, int coluna, int Tf)
{
    if ((letra == 'm') && minas>0) {
        if(campo[coord_l-1][coord_c-1] == '.') {
            campo[coord_l-1][coord_c-1] = 'M';
            minas--;
        }
    } else if (letra == 't') {
        campo[coord_l-1][coord_c-1] = '?';
    } else if (letra == 'l') {
        if (campo[coord_l-1][coord_c-1] == 'M'){
            campo[coord_l-1][coord_c-1] = '.';
            minas++;
        } else if(campo[coord_l-1][coord_c-1] == '?'){
            campo[coord_l-1][coord_c-1] = '.';
        }
    }
    exibe_campo(campo, linha, coluna, Tf);
}

void mostra_local(char gabarito[L][C], char campo[L][C], int coord_l, int coord_c, int& checa_campo)
{
    if(campo[coord_l][coord_c] == '.'){
        campo[coord_l][coord_c] = gabarito[coord_l][coord_c];

        checa_campo--;
    }
}

void revela_vazio(char gabarito[L][C], char campo[L][C], int coord_l, int coord_c, int bomba_l[], int bomba_c[], int& checa_campo, int linha, int coluna)
{
    int c_l = coord_l, c_c = coord_c;

    if((c_l>=1 && c_c>=1) && (campo[c_l-1][c_c-1] == '.' || campo[c_l-1][c_c-1] == '?')) {
        mostra_local(gabarito, campo, c_l-1, c_c-1, checa_campo);
        if(gabarito[c_l-1][c_c-1] == '_') {
            revela_vazio(gabarito, campo, c_l-1, c_c-1, bomba_l, bomba_c, checa_campo, linha, coluna);
        }
    }
    if(c_l>=1 && (campo[c_l-1][c_c] == '.' || campo[c_l-1][c_c] == '?')) {
        mostra_local(gabarito, campo, c_l-1, c_c, checa_campo);
        if(gabarito[c_l-1][c_c] == '_') {
            revela_vazio(gabarito, campo, c_l-1, c_c, bomba_l, bomba_c, checa_campo, linha, coluna);
        }
    }
    if((c_l>=1 && c_c<=(coluna-2)) && (campo[c_l-1][c_c+1] == '.' || campo[c_l-1][c_c+1] == '?')) {
        mostra_local(gabarito, campo, c_l-1, c_c+1, checa_campo);
        if(gabarito[c_l-1][c_c+1] == '_') {
            revela_vazio(gabarito, campo, c_l-1, c_c+1, bomba_l, bomba_c, checa_campo, linha, coluna);
        }
    }
    if(c_c>=1 && (campo[c_l][c_c-1] == '.' || campo[c_l][c_c-1] == '?')) {
        mostra_local(gabarito, campo, c_l, c_c-1, checa_campo);
        if(gabarito[c_l][c_c-1] == '_') {
            revela_vazio(gabarito, campo, c_l, c_c-1, bomba_l, bomba_c, checa_campo, linha, coluna);
        }
    }
    if(c_c<=(coluna-2) && (campo[c_l][c_c+1] == '.' || campo[c_l][c_c+1] == '?')) {
        mostra_local(gabarito, campo, c_l, c_c+1, checa_campo);
        if(gabarito[c_l][c_c+1] == '_') {
            revela_vazio(gabarito, campo, c_l, c_c+1, bomba_l, bomba_c, checa_campo, linha, coluna);
        }
    }
    if((c_l<=(linha-2) && c_c>=1) && (campo[c_l+1][c_c-1] == '.' || campo[c_l+1][c_c-1] == '?')) {
        mostra_local(gabarito, campo, c_l+1, c_c-1, checa_campo);
        if(gabarito[c_l+1][c_c-1] == '_') {
            revela_vazio(gabarito, campo, c_l+1, c_c-1, bomba_l, bomba_c, checa_campo, linha, coluna);
        }
    }
    if(c_l<=(linha-2) && campo[c_l+1][c_c] == '.' || campo[c_l+1][c_c] == '?') {
        mostra_local(gabarito, campo, c_l+1, c_c, checa_campo);
        if(gabarito[c_l+1][c_c] == '_') {
            revela_vazio(gabarito, campo, c_l+1, c_c, bomba_l, bomba_c, checa_campo, linha, coluna);
        }
    }
    if((c_l<=(linha-2) && c_c<=(coluna-2)) && (campo[c_l+1][c_c+1] == '.' || campo[c_l+1][c_c+1] == '?')) {
        mostra_local(gabarito, campo, c_l+1, c_c+1, checa_campo);
        if(gabarito[c_l+1][c_c+1] == '_') {
            revela_vazio(gabarito, campo, c_l+1, c_c+1, bomba_l, bomba_c, checa_campo, linha, coluna);
        }
    }
}

int vizinhanca(int c_l, int c_c, int bomba_l[], int bomba_c[], int B)
{
    int cont=0;

    if(verifica_bomba(c_l-1, c_c-1, bomba_l, bomba_c, B)) {
        cont++;
    }
    if(verifica_bomba(c_l-1, c_c, bomba_l, bomba_c, B)) {
        cont++;
    }
    if(verifica_bomba(c_l-1, c_c+1, bomba_l, bomba_c, B)) {
        cont++;
    }
    if(verifica_bomba(c_l, c_c-1, bomba_l, bomba_c, B)) {
        cont++;
    }
    if(verifica_bomba(c_l, c_c+1, bomba_l, bomba_c, B)) {
        cont++;
    }
    if(verifica_bomba(c_l+1, c_c-1, bomba_l, bomba_c, B)) {
        cont++;
    }
    if(verifica_bomba(c_l+1, c_c, bomba_l, bomba_c, B)) {
        cont++;
    }
    if(verifica_bomba(c_l+1, c_c+1, bomba_l, bomba_c, B)) {
        cont++;
    }
    return cont;
}

bool verifica_bomba(int coord_l, int coord_c, int bomba_l[], int bomba_c[], int B)
{
    for(int k=0; k<B; k++) {
        if(coord_l == bomba_l[k] && coord_c == bomba_c[k]) {
            return true;
        }
    }
    return false;
}

void fim_de_jogo(char gabarito[L][C], char campo[L][C], int linha, int coluna)
{
    for(int i=0; i<linha; i++){
        for(int j=0; j<coluna; j++){
            if((campo[i][j] == '.' || campo[i][j] == '?') && gabarito[i][j] == '*'){
                campo[i][j] = gabarito[i][j];
            }
            if(campo[i][j] == 'M' && gabarito[i][j] != '*'){
                campo[i][j] = 'X';
            }
        }
    }
}
