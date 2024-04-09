
void setup() {
 pinMode(2, INPUT);//A
 pinMode(3, INPUT);//B
 pinMode(4, INPUT);//C
 pinMode(5, INPUT);//D
 pinMode(6, INPUT_PULLUP); //X
 pinMode(7, INPUT_PULLUP); //Y
 pinMode(8, INPUT_PULLUP); //Z

 pinMode(9, OUTPUT); // Residuo
 pinMode(10, OUTPUT); // Infinito
 pinMode(11, OUTPUT); // Suma,Producto,Divisor,Verdadero
 pinMode(12, OUTPUT); // Acarreo,cociente
 pinMode(13, OUTPUT); // Error
}
void loop() {
   int X = digitalRead(6);
   int Y = digitalRead(7);
   int Z = digitalRead(8);
  //////////////////////////////////////////////////////Suma |0|0|0|
 if (!X && !Y && !Z) { 
   int A = digitalRead(2);
   int B = digitalRead(3);
   int C = digitalRead(4);
   int D = digitalRead(5); 
   int resultado = (A ^ B ^ C ^ D); // Suma sin acarreo
   int acarreo = ((A & B) | (C & (A ^ B)) | (D & (A | B))); // Cálculo del acarreo
   digitalWrite(11, resultado);
   digitalWrite(12, acarreo);
   digitalWrite(13, LOW); 
 }
 ////////////////////////////////////////////////// Resta |0|0|1|
 if (!X && !Y && Z) { 
 digitalWrite(11, LOW);
   digitalWrite(12, LOW);
    int a = digitalRead(2);
    int b = digitalRead(3);
    int c = digitalRead(4);
    int d = digitalRead(5); 
    int resultado = (a & !b & !c & !d) | (!a & !b & c & d) | (!a & b & !c & d) | (!a & b & c & !d);

    digitalWrite(11, resultado);
  }
 ////////////////////////////////////////////////// Multiplicacion |0|1|0|
 if (!X && Y && !Z) { 
   digitalWrite(11, LOW);
   digitalWrite(12, LOW);
   int A = digitalRead(2);
   int B = digitalRead(3);
   int C = digitalRead(4);
   int D = digitalRead(5);
   int producto = A & B & C & D; 
   digitalWrite(11, producto); 
 }
 else {
   digitalWrite(11, LOW);
 }
  if (!X && Y && Z) { /////////////////////// División|0|1|1|
   int A = digitalRead(2);
   int B = digitalRead(3);
   int C = digitalRead(4);
   int D = digitalRead(5);
    if (!A && !B && !C && !D){
      digitalWrite(13,HIGH);
      }else{
      digitalWrite(13,LOW);
    }

    if((!B && C && !D) ||  (A && !B && !D)){
      digitalWrite(10, HIGH);
        }else{
      digitalWrite(10, LOW);
      }

    if(B && C && !D){
      digitalWrite(11, HIGH);
    }else{
      digitalWrite(11, LOW);
    }

    if((!B && C && D) ||  (A && B && !D) || (A && B && C)) {
      digitalWrite(12, HIGH);
    }else{
      digitalWrite(12,LOW);
    }

    if(!A && B && C && D){
      digitalWrite(9,HIGH);
    }else{
      digitalWrite(9,LOW);
    }
    

  } else {
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);    
   digitalWrite(11, LOW);
   digitalWrite(12, LOW);
   digitalWrite(13, LOW);
 }

//////////////////////////////////////////////////////AND |1|0|0|
 if (X && !Y && !Z) { 
   int A = digitalRead(2);
   int B = digitalRead(3);
   int C = digitalRead(4);
   int D = digitalRead(5); 
   int OP = (A & B & C & D); 
   digitalWrite(11, OP);
  }else {
   digitalWrite(11, LOW);
 }
    
 //////////////////////////////////////////////////////XOR |1|0|1|
 if (X && !Y && Z) { 
   int A = digitalRead(2);
   int B = digitalRead(3);
   int C = digitalRead(4);
   int D = digitalRead(5); 
   int OP = (A ^ B ^ C ^ D);
   digitalWrite(11, OP);
  }else {
   digitalWrite(11, LOW);
 }
 //////////////////////////////////////////////////////OR |1|1|0|
 if (X && Y && !Z) { 
   int A = digitalRead(2);
   int B = digitalRead(3);
   int C = digitalRead(4);
   int D = digitalRead(5); 
   int OP = (A || B || C || D); 
   digitalWrite(11, OP);
  }else {
   digitalWrite(11, LOW);
 }
 //////////////////////////////////////////////////////NOT |1|1|1|
 if (X && Y && Z) { 
   int A = digitalRead(2);
   int B = digitalRead(3);
   int C = digitalRead(4);
   int D = digitalRead(5); 
  if (A == LOW) {
    digitalWrite(11, HIGH);  
  } else {
    digitalWrite(11, LOW); 
  }
  if (B == LOW) {
    digitalWrite(12, HIGH); 
  } else {
    digitalWrite(12, LOW); 
  }
  if (C == LOW) {
    digitalWrite(10, HIGH); 
  } else {
    digitalWrite(10, LOW); 
  }
  if (D == LOW) {
    digitalWrite(9, HIGH); 
  } else {
    digitalWrite(9, LOW); 
  }
}
}