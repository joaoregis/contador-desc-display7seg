// Pinos de saída do display do arduino
int A = 2, B = 3, C = 4, D = 5, E = 6, F = 7, G = 8, DECIMALPOINT = 11;

// Representação binária dos números
int Numbers[10][8] = {

  //A   B   C   D   E   F   G   DP
  // Binário                                  || Char   || Pos
  {LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW},          // NULL   | 0
  {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW,LOW},    // 0      | 1
  {LOW,HIGH,HIGH,LOW,LOW,LOW,LOW,LOW},        // 1      | 2
  {HIGH,HIGH,LOW,HIGH,HIGH,LOW,HIGH,LOW},     // 2      | 3
  {LOW,HIGH,HIGH,HIGH,LOW,LOW,HIGH,LOW},      // 3      | 4
  {HIGH,HIGH,HIGH,LOW,LOW,HIGH,HIGH,LOW},     // 4      | 5
  {HIGH,LOW,HIGH,HIGH,LOW,HIGH,HIGH,LOW},     // 5      | 6
  {HIGH,LOW,HIGH,HIGH,HIGH,HIGH,HIGH,LOW},    // 6      | 7
  {HIGH,HIGH,HIGH,LOW,LOW,LOW,LOW,LOW},       // 7      | 8
  {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW},   // 8      | 9
  {HIGH,HIGH,HIGH,HIGH,LOW,HIGH,HIGH,LOW},    // 9      | 10
  
};

// Número que a contagem regressiva de inicia (Máximo = 9)
int startNumber = 10;

// Configurando pinos de saída
void setup()
{
  int i = 0;

  // Percorre os pinos do 2º até o 8º definindo como output
  for (i = 2; i <= 8; i++)
  {
    pinMode(i, OUTPUT);
  }

  pinMode(DECIMALPOINT, OUTPUT);
}

// Renderiza o número correspondente ao startNumber no display
void WriteOnDisplay()
{
    digitalWrite(A, Numbers[startNumber][0]);
    digitalWrite(B, Numbers[startNumber][1]);
    digitalWrite(C, Numbers[startNumber][2]);
    digitalWrite(D, Numbers[startNumber][3]);
    digitalWrite(E, Numbers[startNumber][4]);
    digitalWrite(F, Numbers[startNumber][5]);
    digitalWrite(G, Numbers[startNumber][6]);
    digitalWrite(DECIMALPOINT, Numbers[startNumber][7]);
    delay(1000);
}

void loop()
{

  WriteOnDisplay();

  startNumber--;

  if (startNumber < 0)
  {
    startNumber = 9;
  }

}
