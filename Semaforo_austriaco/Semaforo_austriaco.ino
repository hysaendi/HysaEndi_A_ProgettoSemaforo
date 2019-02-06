 //dichiarazione variabili con la quale richiamo i pin
    int rosso1;
    int giallo1;
    int verde1; 
    int rosso2;
    int giallo2;
    int verde2;
    int numlampeggi;
    int richiesta;
    int durataTotale;
    int durataGiallo;
    int lassotempoVerde;
    int temporosso;

void richiediDurataVerde ();
        
void setup() {
  // put your setup code here, to run once:

    rosso1 = 2;
    giallo1= 3;
    verde1= 4;
    rosso2 = 5;
    giallo2 = 6;
    verde2 = 7;
    
  
    pinMode (rosso1, OUTPUT);
    pinMode (giallo1, OUTPUT);
    pinMode (verde1, OUTPUT);
    pinMode (rosso2, OUTPUT);
    pinMode (giallo2, OUTPUT);
    pinMode (verde2, OUTPUT);

    richiesta = 0;

    temporosso = durataTotale - durataGiallo;
    
    Serial.begin (9600);
    
}
   
void loop() {
  // put your main code here, to run repeatedly:
    if (richiesta == 0)
    {
      richiediValori();
    }
    richiesta = 1;



    


    


  
        
       
}


   void richiediValori ()
   {
    richiediDurataTotale();
    richiediDurataGiallo();
    richiediDurataVerde();
    richiediLampeggiVerde();
   }

  void richiediLampeggiVerde()
  {
    Serial.println("Quanti lampeggi verdi?");
    while (Serial.available() == 0) {};
    String input = Serial.readString();
    numlampeggi = input.toInt(); 
  }

  void richiediDurataTotale()
  {
    Serial.println("Quanto deve durare il semaforo?");
    while (Serial.available() == 0) {};
    String input = Serial.readString();
    durataTotale = input.toInt();
         
  }

  void richiediDurataGiallo ()
  {
    Serial.println ("Quanto deve durare il giallo?");
    while (Serial.available() == 0) {};
    String input = Serial.readString();
    durataGiallo = input.toInt();  
  }
  
  void richiediDurataVerde ()
  {
    Serial.println("Quanto lasso di tempo vuoi che ci sia da un lampeggio all'altro?");
    while (Serial.available() == 0) {};
    String input = Serial.readString();
    lassotempoVerde = input.toInt();
        
  }


  void lampeggiaVerde (int n, int ritardo)
  {
    for (int i = 0; i<= n; i++)
    {
      digitalWrite (verde2,HIGH);
      delay (ritardo);
      digitalWrite (verde2,LOW);
      delay (ritardo);
    }
  }




