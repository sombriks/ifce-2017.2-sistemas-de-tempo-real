
elabore um programa concorrente em que 3 processos, p1, p2 e p3 devem 
enviar periodicamente valores aleatórios para uma quarta thread chamada 
'driver'. a thread 'driver' deve receber os valores, e retornar para 
a thread que enviou o valor inteiro 1, e as demais thread o valor 0. 
cada thread que receber o seu valor da 'driver', deverá imprimir 
"maior valor" se receber 1, e "menor valor" se receber 0.
