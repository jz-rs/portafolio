#include <iostream>
#include <unordered_map>
#include<vector>
#include<conio.h>
#include<stdio.h>>
#include<string.h>
#include<windows.h>
#include<Math.h>
#include <queue>

using namespace std;

//---------------------------------------------------------Fuerza Bruta----------------------------------------------------------------------------

void bruta(){
	char texto[100], patron[50];
	cout<<"Ingrese el Texto: "<<endl;
	cin>>texto;
	cout<<"Ingrese el patron: "<<endl;
	cin>>patron;
	if(strstr(texto, patron)==0){
		cout<<"El patron "<<patron<<" no se encuentra en el texto."<<endl;
	}
	else{
		cout<<"El patron "<<patron<<" se encontro."<<endl;
	}
}

//---------------------------------------------------------KMP----------------------------------------------------------------------------


void KMP(){
	char texto[100], patron[50];
	int cantidad=0, cantidad2=0,contador=0,contador2=0, var=0;
	cout<<"Ingrese texto principal: "<<endl;
	cin>>texto;
	cout<<"Ingrese patron: "<<endl;
	cin>>patron;

	cantidad=strlen(texto);
	cantidad2=strlen(patron);
	
	int i=var, contador3=0;
	
	do{
		i=var;
		
		for(int j=0; j<cantidad2;j++){
			if(texto[i]==patron[j]){
				i++;
				contador2++;
				//cout<<i<<endl;
			}
		}
		
		if(contador2==cantidad2){
			contador=1;
			cout<<"Se encontro el patron en el texto, posicion: "<<contador3<<endl;
		}
		else{
			contador2=0;
			var++;
			//cout<<"Todo mal"<<endl;
			if(var==cantidad-1){
				contador=1;
			}
		}
		i=var;
		contador3++;
	}while(contador==0);
	
	if(contador2!=cantidad2){
			cout<<"No se encontro"<<endl;
		}
}

//---------------------------------------------------------ZLW----------------------------------------------------------------------------

vector<int> encoding(string s1) {
	cout << "\nCodificacion:\n";
	unordered_map<string, int> table;
	for (int i = 0; i <= 255; i++) {
		string ch = "";
		ch += char(i);
		table[ch] = i;
	}

	string p = "", c = "";
	p += s1[0];
	int code = 256;
	vector<int> codigoSalida;
	cout << "String\tCodigo_salida\			\n";
	for (int i = 0; i < s1.length(); i++) {
		if (i != s1.length() - 1)
			c += s1[i + 1];
		if (table.find(p + c) != table.end()) {
			p = p + c;
		}
		else {
			cout << p << "\t" << table[p] << "\t\t" << p + c << "\t" << code << endl;
			codigoSalida.push_back(table[p]);
			table[p + c] = code;
			code++;
			p = c;
		}
		c = "";
	}
	cout << p << "\t" << table[p] << endl;
	codigoSalida.push_back(table[p]);
	return codigoSalida;
}

void ZLW(){
	

	string s;
	cout << "Ingrese texto: "<<endl;
	cin >> s;
	vector<int> codigoSalida = encoding(s);
	cout << "Codigo de salida: "<<endl;
	for (int i = 0; i < codigoSalida.size(); i++) {
		cout << codigoSalida[i] << " ";
	}
	cout << endl;
}
//---------------------------------------------------------AFIN----------------------------------------------------------------------------

void Afin() {

	char mensaje[50];//palabra
	int codigo[40], cont;//pala-cod
	char alf[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

    cout << "Ingrese el mensaje a cifrar: "<<endl; 
    cin>>mensaje;
    
    int longitud = strlen(mensaje);

    for (int j = 0; j < longitud; j++) {
	    cont = 0;
    for (int i = 0; i < 26; i++) {
		if (mensaje[j] == alf[i]) {
			codigo[j] = ((13 * cont) + 2) % 27;  
		}
		cont++;
	}
    }
    cout << "codigo: "<<endl;
    for (int g = 0; g < longitud; g++) {
	    cout<< alf[codigo[g]];
	}
}


//---------------------------------------------------------Cifrado Cesar----------------------------------------------------------------------------
char alf[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
void cesar() {
	char mensaje[100];
	fflush(stdin);//limpieza del buffer, como saltos de lineas y espacios
	cout << "Ingrese mensaje a cifrar: "<<endl;
	cin.getline(mensaje, 100);
	for (int i = 0; i < strlen(mensaje);i++) {
		if (mensaje[i] != 32) {
			for (int j = 0; j < strlen(alf); j++) {
				if (mensaje[i] == alf[j]) {
					int aux = (j + 3) % 26;
					mensaje[i] = alf[aux];
					break;
				}
			}
		}
	}
	cout << "El mensaje cifrado es: " <<endl << mensaje << endl << endl;
}
void descifrado_cesar() {
	char mensaje[100];
	//char alf[26];
	//char alf[]={ " a " , " b ", " c ", " d ", " e ", " f ", " g ", " h ", " i ", " j ", " k ", " l ", " m ", " n ", " o ", " p ", " q ", " r ", " s ", " t ", " u ", " v ", " w ", " x ", " y ", " z "};
	fflush(stdin);//limpieza del buffer, como saltos de lineas y espacios
	cout << "Ingrese mensaje a descifrar: "<<endl;
	cin.getline(mensaje, 100);
	for (int i = 0; i < strlen(mensaje); i++) {
		if (mensaje[i] != 32) {
			for (int j = 0; j < strlen(alf); j++) {
				if (mensaje[i] == alf[j]) {
					int aux;
					if ((j - 3) < 0) {
						aux = 26 + (j - 3);
					}
					else {
						aux = (j - 3) % 26;
					}
					mensaje[i] = alf[aux];
					break;
				}
			}
		}
	}
	cout << "El mensaje descifrado es: " <<endl << mensaje << endl << endl;
}
//---------------------------------------------------------Playfair----------------------------------------------------------------------------

int esta_matriz(char letra, char matriz[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (letra == matriz[i][j]) {
				return 1;
			}
		}
	}
	return -1;
}

void llenar_matriz(char clave[], char matriz[5][5]) {
	int fila = 0, columna = 0, aux = 0;
	for (int i = 0; i < strlen(clave); i++) {
		aux = esta_matriz(clave[i], matriz);
		if (aux == -1 && clave[i] != 106) {
			if (columna == 5) {
				fila++;
				columna = 0;
			}
			matriz[fila][columna] = clave[i];
			columna++;
		}
	}
	for (int j = 0; j < strlen(alf); j++) {
		aux = esta_matriz(alf[j], matriz);
		if (aux == -1 && alf[j] != 106) {
			if (columna == 5) {
				fila++;
				columna = 0;
			}
			matriz[fila][columna] = alf[j];
			columna++;
		}
	}
}

void acomodar_mensaje(char m2[], char m[]) {
	int j = 0;
	for (int i = 0; i < strlen(m); i++) {
		if (m[i] != 32) {
			m2[j] = m[i];
			j++;
		}
	}
	m2[j] = '\0';

	int i = 0;
	j = 1;
	while (j <= strlen(m2)) {
		if (m2[i] == m2[j]) {
			for (int k = strlen(m2) + 1; k > j; k--) {
				m2[k] = m2[k - 1];
			}
			m2[j] = 'x';
		}
		i = i + 2;
		j = j + 2;
	}

	if (strlen(m2) % 2 != 0) {
		m2[strlen(m2) + 1] = '\0';
		m2[strlen(m2)] = 'x';
	}
}

void Playfair() {
	char m[100], clave[100];
	fflush(stdin);
	cout << "Ingrese mensaje a cifrar:"<<endl;
	cin.getline(m, 100);
	fflush(stdin);
	cout << "Ingrese clave:"<<endl;
	cin.getline(clave, 100);
	char matriz[5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			matriz[i][j] = '\0';

	llenar_matriz(clave, matriz);

	fflush(stdin);
	char m2[100];
	acomodar_mensaje(m2, m);

	int i = 0, j = 1;
	while (j <= strlen(m2)) {
		int fila1, fila2, columna1, columna2;
		if (m2[i] == 'j') {
			m2[i] = 'i';
		}
		if (m2[j] == 'j') {
			m2[j] = 'i';
		}
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				if (m2[i] == matriz[x][y]) {
					fila1 = x;
					columna1 = y;
				}
				if (m2[j] == matriz[x][y]) {
					fila2 = x;
					columna2 = y;
				}
			}
		}
		if (fila1 == fila2) {
			m2[i] = matriz[fila1][(columna1 + 1) % 5];
			m2[j] = matriz[fila1][(columna2 + 1) % 5];
		}
		else if (columna1 == columna2) {
			m2[i] = matriz[(fila1 + 1) % 5][columna1];
			m2[j] = matriz[(fila2 + 1) % 5][columna1];
		}
		else {
			m2[i] = matriz[fila1][columna2];
			m2[j] = matriz[fila2][columna1];
		}
		i = i + 2;
		j = j + 2;
	}
	cout << "El mensaje cifrado es:"<<endl;
	for (int i = 0; i < strlen(m2); i++) {
		cout << m2[i];
		if (i % 2 != 0) {
			cout << " ";
		}
	}
	cout << endl << endl;
}
//---------------------------------------------------------Huffman----------------------------------------------------------------------------

// A Tree node
struct Node
{
	char ch;
	int freq;
	Node *left, *right;
};

// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

// Comparison object to be used to order the heap
struct comp
{
	bool operator()(Node* l, Node* r)
	{
		// highest priority item has lowest frequency
		return l->freq > r->freq;
	}
};

// traverse the Huffman Tree and store Huffman Codes
// in a map.
void encode(Node* root, string str,
			unordered_map<char, string> &huffmanCode)
{
	if (root == nullptr)
		return;

	// found a leaf node
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

// traverse the Huffman Tree and decode the encoded string
void decode(Node* root, int &index, string str)
{
	if (root == nullptr) {
		return;
	}

	// found a leaf node
	if (!root->left && !root->right)
	{
		cout << root->ch;
		return;
	}

	index++;

	if (str[index] =='0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}

// Builds Huffman Tree and decode given input text
void Huffman(string text)
{
	// count frequency of appearance of each character
	// and store it in a map
	unordered_map<char, int> freq;
	for (char ch: text) {
		freq[ch]++;
	}

	// Create a priority queue to store live nodes of
	// Huffman tree;
	priority_queue<Node*, vector<Node*>, comp> pq;

	// Create a leaf node for each character and add it
	// to the priority queue.
	for (auto pair: freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	// do till there is more than one node in the queue
	while (pq.size() != 1)
	{
		// Remove the two nodes of highest priority
		// (lowest frequency) from the queue
		Node *left = pq.top(); pq.pop();
		Node *right = pq.top();	pq.pop();

		// Create a new internal node with these two nodes
		// as children and with frequency equal to the sum
		// of the two nodes' frequencies. Add the new node
		// to the priority queue.
		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	// root stores pointer to root of Huffman Tree
	Node* root = pq.top();

	// traverse the Huffman Tree and store Huffman Codes
	// in a map. Also prints them
	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);

	cout << "Los codigos de Huffman son: " << endl;
	for (auto pair: huffmanCode) {
		cout << pair.first << " " << pair.second << endl;
	}

	cout << "La cadena original era: " << text << endl;

	// print encoded string
	string str = "";
	for (char ch: text) {
		str += huffmanCode[ch];
	}

	cout << "La cadena codificada es: " << str << endl;

	// traverse the Huffman Tree again and this time
	// decode the encoded string
	int index = -1;
	cout << "La cadena decodificada es: "<<endl;
	while (index < (int)str.size() - 2) {
		decode(root, index, str);
	}
}
//---------------------------------------------------------Vigenere----------------------------------------------------------------------------

void Vigenere() {
	int aux1 = 0, aux2 = 0, aux3 = 0;
	char mensaje[100], clave[100];
	fflush(stdin);
	cout << "Ingrese mensaje a cifrar:"<<endl;
	cin.getline(mensaje, 100);

	cout << "Ingrese clave:"<<endl;
	cin.getline(clave, 100);

	int k = 0;
	for (int i = 0; i < strlen(mensaje); i++) {
		if (mensaje[i] != 32) {
			for (int j = 0; j < strlen(alf); j++) {
				if (mensaje[i] == alf[j]) {
					aux1 = j;
				}
				if (clave[k % strlen(clave)] == alf[j]) {
					aux2 = j;
				}
			}
			aux3 = (aux1 + aux2) % 26;
			mensaje[i] = alf[aux3];
			k++;
		}
	}
	cout << "El mensaje cifrado es:" << mensaje << endl;
}

//---------------------------------------------------------Hill----------------------------------------------------------------------------
void hill(){
	  int x, y, i, j, k, n;
    cout << "Ingrese el tamano de la matriz clave:"<<endl;
    cin >> n;

    cout << "Ingrese la matriz clave"<<endl;
    int a[10][10];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << "[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
    cout << "Ingrese el mensaje a encriptar: "<<endl;
    string s;
    cin >> s;
    int temp = (n - s.size() % n) % n;
    for (i = 0; i < temp; i++) {
        s += 'x';
    }
    k = 0;
    string ans = "";
    while (k < s.size()) {
        for (i = 0; i < n; i++) {
            int sum = 0;
            int temp = k;
            for (j = 0; j < n; j++) {
                sum += (a[i][j] % 26 * (s[temp++] - 'a') % 26) % 26;
                sum = sum % 26;
            }
            ans += (sum + 'a');
        }
        k += n;
    }
    cout << "Palabra codificada: " << ans << '\n';
}

void menu(){
	
	system("cls");
	
	string text;
	int op1=0;
	
    cout<<"1) Fuerza Bruta"<<endl;  
    cout<<"2) KMP"<<endl; 
    cout<<"3) ZLW"<<endl;
    cout<<"4) Afin"<<endl;
    cout<<"5) Cesar"<<endl;
    cout<<"6) PLAYFAIR"<<endl;
    cout<<"7) Huffman"<<endl;
    cout<<"8) Vigenere"<<endl;
    cout<<"9) Hill"<<endl;
    cout<<"0) Salir"<<endl; 
    cout<<"\nIngrese opcion: ";
	cin>>op1; 
switch(op1){
case 1:
	system("cls");
    
    cout << "ALGORITMO DE FUERZA BRUTA\n\n";
    bruta();
    
    system("pause");
    menu();
break;

case 2:
	system("cls");
	
	cout << "ALGORITMO KMP\n\n";
	KMP();
	system("pause");
	
	menu();
	
break;
case 3:
	system("cls");
	
	cout << "ALGORITMO DE ZIV-LEMPEL-WELCH\n\n";
	ZLW();
	system("pause");
	
	menu();
	
break;
case 4:
	system("cls");
	
	cout << "CIFRADO AFIN\n\n";
	Afin();
	cout<<endl;
	system("pause");
	
	menu();
	
break;
case 5:
	system("cls");
	
	cout << "CIFRADO CESAR\n\n";
	int op;
   do{
	 cout<<"1) Cifrar mensaje:"<<endl;
	 cout<<"2) Descrifrar mensaje:"<<endl;
	 cout<<"3) Menu"<<endl;
	 cin>>op;
	 
	switch (op)
    {
	case 1: 
	{
	cesar(); 
	system("pause");
    system("cls");
	break;
	}
	case 2: 
	{
	descifrado_cesar();
	system("pause");
    system("cls"); 
	break;	
	}
	case 3:
    {
    menu();
    break;
    };
    default:
    cout << "Esa opcion no es valida" << endl;
    system("pause");
    system("cls");
    break;
    }
   
   }while(op!=3);
	system("pause");
	
	menu();
	
break;
case 6:
	system("cls");
	
	cout << "CIFRADO PLAYFAIR\n\n";
	Playfair();
	system("pause");
	
	menu();
	
break;
case 7:
	system("cls");
	
	cout << "CIFRADO HUFFMAN\n\n";
	
	cout<<"Ingrese texto: "<<endl;
	cin>>text;
	
	Huffman(text);
	cout<<endl;
	system("pause");
	
	menu();
	
break;
case 8:
	system("cls");
	
	cout << "CIFRADO VIGENERE\n\n";
	
	Vigenere();
	system("pause");
	
	menu();
	
break;
case 9:
	system("cls");
	
	cout << "CIFRADO HILL\n\n";
	hill();
	system("pause");
	
	menu();
	
break;
default: 
        system("cls");  
        cout<<"\n\n\t¡Gracias por usar nuestro programa!"; //manejo de excepciones.
        cout<<"\n";	
		break;
	}
}
int main(){
	menu();
	return 0;
}