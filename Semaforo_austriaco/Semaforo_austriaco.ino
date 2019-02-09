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
    int durataVerde;
    int lassotempoVerde;
    int durataRosso;

        
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

    
    Serial.begin (9600);
    
}
   
void loop() {
  // put your main code here, to run repeatedly:
    if (richiesta == 0)
    {
      richiediValori();
    }
    richiesta = 1;     //impongo richiesta = 1 cosi  le domande verranno effettuate una sola volta

    int durataRosso = durataTotale - durataGiallo;
    int durataVerde = durataRosso - numlampeggi * lassotempoVerde *2;
    

   //inizializzazione semaforo
    digitalWrite (rosso1,HIGH);
    digitalWrite (verde2,HIGH);
    delay (durataVerde);
    lampeggiaVerde2();
    //fase in cui rosso e giallo restano accesi
    rossoEgialloAccesi();
    //fase in cui il verde rimane illuminato con un delay calcolato
    verdeAcceso();
    
    //giallo rimane accesso per poi ricominciare il ciclo
    gialloAcceso();
  

  
        
       
}


   void richiediValori ()
   {
    richiediDurataTotale();
    richiediDurataGiallo();    
    richiediLampeggiVerde();
    richiediLassoTempoVerde();
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
    Serial.println("Quanto deve durare il semaforo? (input in ms)");
    while (Serial.available() == 0) {};
    String input = Serial.readString();
    durataTotale = input.toInt();
         
  }

  void richiediDurataGiallo ()
  {
    Serial.println ("Quanto deve durare il giallo?(input in ms)");
    while (Serial.available() == 0) {};
    String input = Serial.readString();
    durataGiallo = input.toInt();  
  }


  void richiediLassoTempoVerde()
  {
    Serial.println ("Quanto tempo vuoi che ci sia da un lampeggio all'altro?(input in ms)");
    while (Serial.available() == 0) {};
    String input = Serial.readString();
    lassotempoVerde = input.toInt(); 
  }
  


  void lampeggiaVerde2 ()
  {
    for (int i = 0; i< numlampeggi; i++)
    {
      digitalWrite (verde2,HIGH);
      delay (lassotempoVerde);
      digitalWrite (verde2,LOW);
      delay (lassotempoVerde);
    }    
  }


    void rossoEgialloAccesi()
    {
    digitalWrite (giallo1,HIGH);                            
    digitalWrite (giallo2,HIGH);
    delay (durataGiallo);               //creazione metodo void rossoEgialloAccesi () con all'interno le righe di codice                                                                           
    digitalWrite (giallo1,LOW);                                             
    digitalWrite (giallo2,LOW);
    digitalWrite (rosso1,LOW);
      
    }


    void verdeAcceso()
    {
    digitalWrite (rosso2,HIGH);
    digitalWrite (verde1,HIGH);
    delay (durataVerde);
    digitalWrite (verde1,LOW);
    delay (0);                                                //metodo void  VerdeAcceso () {}
    lampeggiaVerde1();
    delay (0);
    digitalWrite (rosso2,LOW);
    delay (0);
    digitalWrite (rosso2,LOW),
    delay (0);
      
    }


    void gialloAcceso()
    {
    digitalWrite (giallo1,HIGH);
    digitalWrite (rosso2,HIGH);
    digitalWrite (giallo2,HIGH);
    delay (durataGiallo);                                         //metodo void gialloAcceso () {}
    digitalWrite (giallo1,LOW);
    digitalWrite (giallo2,LOW);
    digitalWrite (rosso2,LOW);
    delay (0);
    }



    void lampeggiaVerde1()
    {
      for (int i = 0; i< numlampeggi; i++)
    {
      digitalWrite (verde1,HIGH);
      delay (lassotempoVerde);
      digitalWrite (verde1,LOW);
      delay (lassotempoVerde);
    }    
    }







  
