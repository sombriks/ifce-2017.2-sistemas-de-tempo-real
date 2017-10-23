# 2017-10-23 - exercício para avaliação

  Dada uma aplicação com 5 blocos de memória de 2k, elabore um algoritmo em que
três threads A() B() C() desejam utilizar as seguintes quantidades de recursos:
A() deseja utilizar 3 recursos, B() deseja utilizar 3 recursos (blocos de 
memória), C() deseja utilizar 2 recursos. Utilize o conceito de semáforo de 
quantidade para alocar os recursos para cada thread.
  Inicialize corretamente o semáforos. Após serem utilizados, todos os recursos
devem ser liberados. Explique o que acontecerá se as operações WAIT() forem 
executadas nesta ordem: A() em primeiro, B() em segundo e C() em terceiro.
