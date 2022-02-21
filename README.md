# ED2_Trabalho_4
## Grupo

- Gabriel Toledo Netto Gribel.
- Marcus Vinícius Rodrigues da Silva.
- Nícolas Moraes.
- Pedro do Couto Filgueiras.

## Problemas
  Tivemos grande dificuldade para gerar o 'make-file', mas conseguimos gerar um arquivo '.exe' que acreditamos que possa compensá-lo.

## Como executar
  Na pasta onde o executável está armazenado (./bin/Debug/) execute o seguinte comando:

```         
.\main [diretório do arquivo .csv]
```

  Após isso o programa irá verificar se existe o arquivo "tiktok_app_reviews.bin" arquivo binário na mesma pasta do executável.
  Se não possuir um arquivo binário ele o criará imprimindo na tela o número de registros gravados.<br>
  
  Caso tenha algum problema para gerar o arquivo binário clique [aqui](https://drive.google.com/drive/folders/19aUpOx9O-iQ_iTyopk2irIskJOty3kDn?usp=sharing)  para ser direcionado a uma pasta no Google Drive onde possui o arquivo binário já pré-processado e outros arquivos CSVs reduzidos.<br>

  Após isso, o programa irá apresentar o menu para interagir com o usuário.<br>

<h2>1 - Comprimir N registros</h2><br>

**Será gerado um arquivo binario (reviewsComp.bin) com toda sequencia de bit gerado.**

<br>

<hr>
 
 <h2>2 - Descomprimir</h2>
 
**Verificará se possui arquivo <reviewsComp.bin> se possuir verificará ainda se a arvore está vazia (caso o programa tenha sido fechado e nao tenha executado a compactação).
após isso, será gerado um arquivo (reviewsOrig.txt) com todos os reviews_texts descompactados.** <br>
     
 <hr>
 
 
<h2>3 - Executa sequencia</h2><br>

**Para executar a sequência, gerará um arquivo <saida.txt> onde terá os casos isolados junto com a média de cada conjunto M.**

<hr>
