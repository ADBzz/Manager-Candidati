# Manager-Candidati
Progetto universitario sviluppato in C++ con il framework Qt 5.15.2

## Funzionalità dell'applicazione
1. **Inserimento nuovi candidati**: L'utente può inserire un nuovo candidato attraverso due modalità:
  importando un file CSV contenente una lista di candidati (così strutturato: nome,cognome,dd/mm/yyyy,genere,occupazione)
  oppure compilando un form per l'aggiunta di un candidato singolo.
2. **Visualizzazione elenco candidati**: L'appliczione mostra l'elenco dei candidati nell'ordine in cui sono stati inseriti.
3. **Modifica/Cancellazione di un candidato**: I candidati possono essere modificati o rimossi dalla tabella selezionandone una cella
  e cliccando il bottone con la funzione desiderata.
4. **Score di idoneità**: L'applicazione permette di inserire per ogni candidato uno score di idoneità.
5. **Gestione dele sessioni di lavoro**: Quando l'utente chiude l'applicazione, l'elenco dei candidati viene salvato,
  inclusi gli score di idoneità assegnati. Quando l'applicazione viene riaperta, i candidati della precedente sessione vengono automaticamente ricaricati.
