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
        

    if (durataTotale < durataGiallo)            //condizione per la quale impongo se l'utente inserisce una durata del giallo piu grande della durata del semaforo
                                                //esso restituisce un "errore"
    {"la durata del giallo è troppo alta";}

    int durataRosso = durataTotale - durataGiallo;
    int durataVerde = durataRosso - numlampeggi * lassotempoVerde *2;

    durataTotale = inputValori ("Quanti deve durare il rosso? (input in ms)", durataTotale);
    durataGiallo = inputValori ("Quanto deve durare il giallo? (input in ms)", durataGiallo);
    numlampeggi = inputValori ("Quanti lampeggi verde?",numlampeggi);
    lassotempoVerde = inputValori ("Quanto tempo vuoi che ci sia da un lampeggi all'altro? (input in ms)",lassotempoVerde);
    richiesta = 1; //do la richiesta = 1 cosi le domande dei valori verranno chieste 1 volta
    
    

   //inizializzazione semaforo
    digitalWrite (rosso1,HIGH);
    digitalWrite (verde2,HIGH);
    delay (durataVerde);
    lampeggiaVerde(verde2, lassotempoVerde, numlampeggi);
    //fase in cui rosso e giallo restano accesi
    rossoEgialloAccesi();
    //fase in cui il verde rimane illuminato con un delay calcolato
    verdeAcceso();    
    //giallo rimane accesso per poi ricominciare il ciclo
    gialloAcceso();
    
               
}

  int inputValori (String frase, int variabile) {
    Serial.println (frase);
    while (Serial.available() == 0) {};
    variabile = Serial.readString().toInt();
    
    return variabile;
  }
  


  void lampeggiaVerde (int led, int lassotempoVerde, int numlampeggi) //metodo stretto con la quale in input ricevo i valori
  {
    for (int i = 0; i< numlampeggi; i++)
    {
      digitalWrite (led,HIGH);
      delay (lassotempoVerde);
      digitalWrite (led,LOW);
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
    lampeggiaVerde(verde1,lassotempoVerde,numlampeggi);
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



 

   







  
