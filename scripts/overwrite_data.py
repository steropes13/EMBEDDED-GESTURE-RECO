import pandas as pd
import argparse
import os

def process_directories(dir_tempi, dir_dati, dir_output):
    # Crea la directory di output se non esiste
    if not os.path.exists(dir_output):
        os.makedirs(dir_output)
        print(f"Cartella di output creata: {dir_output}")

    # Otteniamo la lista dei file nella cartella dei tempi
    # Consideriamo solo i file .csv
    files_tempi = [f for f in os.listdir(dir_tempi) if f.endswith('.csv')]

    if not files_tempi:
        print("Nessun file CSV trovato nella cartella dei tempi.")
        return

    for filename in files_tempi:
        path_tempo = os.path.join(dir_tempi, filename)
        path_dato = os.path.join(dir_dati, filename)
        path_output = os.path.join(dir_output, filename)

        # Verifichiamo se il file corrispondente esiste nella cartella dati
        if os.path.exists(path_dato):
            try:
                print(f"Elaborazione di: {filename}...")
                
                df_tempi = pd.read_csv(path_tempo)
                df_dati = pd.read_csv(path_dato)

                # Prendiamo la colonna temporale dal primo file
                df_dati['millis'] = df_tempi['millis']

                # 3. Salva il risultato
                df_dati.to_csv(path_output, index=False)

                print(f"File generato con successo: {path_output}")
            except Exception as e:
                print(f"Errore durante l'elaborazione di {filename}: {e}")
        else:
            print(f"Salto {filename}: non trovato nella cartella dati.")

    print("\nProcesso completato per tutti i file!")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Combina file CSV da due directory diverse accoppiandoli per nome.")
    parser.add_argument("--times_dir", required=True, help="Directory contenente i file con timestamp corretti.")
    parser.add_argument("--data_dir", required=True, help="Directory contenente i file con dati corretti.")
    
    args = parser.parse_args()  
    
    process_directories(args.times_dir, args.data_dir, args.times_dir)