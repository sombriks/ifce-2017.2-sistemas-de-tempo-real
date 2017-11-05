# Gerenciador de mensagens

Elabore um programa concorrente que execute 8 
threads e um gerenciador de mensagens. As threads 
A(), B(), C(), D() devem "periodicamente" enviar as
mensagens 10, 20, 30 e 40, respectivamente, para o
gerenciador de mensagens, através dos seus 
respectivos canais, 0, 1, 2 e 3. O gerenciador de 
mensagens possui um vetor **local** de 12 elementos 
do tipo inteiro para armazenar as mensagens recebidas 
das threads. Quando o vetor estiver preenchido, o 
gerenciador deverá pegar cada mensagem do seu 
vetor, extrair o identificador da thread destino e 
encaminhar seu respectivo valor via canal de 
comunicação. A mensagem, enviada da thread origem 
para o gerenciador é do tipo inteiro e deve conter 
o identificador da thread destino e seu respectivo 
valor (10, 20, 30 ou 40). 
**Utilize máscara de bits para construir a mensagem.**
O gerenciador deve se comunicar com as threads 
destino E() F() G() H() utiliando os canais 4, 5 , 
6 e 7, respectivamente. Periodicamente, as threads 
destino devem receber seus valores e imprimi-los 
na tela.

## Exemplo de execução

- A constroi com bitmask mensagem pra E e valor 10.
- A envia para o gerenciador a sua mensagem.
- O gerenciador espera receber 12 elementos.
- Se tiver recebido 12, ele sai do modo de 
  recepção e envia todas as mensagens na fila.
- Quando todas as 12 foram enviadas, limpar a 
  lista e voltar a ouvir mensagens
