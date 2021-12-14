<h1 align="center"> 
 Trabalho AEDS|CEFET 
</h1>
<h4 align="center">	
  Este trabalho consiste na implementação da estrutura da árvore vermelho-preto, bem como, sua comparação com as árvores binária e AVL.
</h4>
<h1></h1>

### Realização da média

<p> Foi realizada o cálculo da média do tempo de inserção e de pesquisa a partir dos resultados realizados 10 vezes. O resultado foi representado na forma de gráficos separados a a partir da quantidade de dados que o programa usou. Desse modo, esta dividido em 3 gráficos, um usando a base de 1000, 100000 e 1000000 números do tipo float. Nesse mesmo critério, foi feito um gráfico para representar o tempo de inserção desse dados <p>

<img src="https://user-images.githubusercontent.com/78819692/145930700-25cc8505-7858-473d-b642-cd20f8c55118.png" width="700">
<img src="https://user-images.githubusercontent.com/78819692/145930989-4d30abad-99ba-48cd-ad78-cb654b03880e.png" width="700">
<img src="https://user-images.githubusercontent.com/78819692/145931000-f2ca1297-d326-4eac-bdc7-a224e69062d7.png" width="700">
<img src="https://user-images.githubusercontent.com/78819692/145931092-2e2a5d0a-4f56-45e3-865e-e2065efac79a.png" width="700">

<h1></h1>

### Exemplos da saída do programa:

<p>Exemplo de algumas saídas salvas para realizar o calculo da média (Árvore binária).<p>


<img src="https://user-images.githubusercontent.com/78819692/145931995-9e8f910a-8f29-4268-a547-1c3c2c8f602a.png" width="1000">

## Discussão:
 
### Binária vs AVL 
 
<p> Na comparação entre essa duas estruturas reparamos que a medida que aumentamos o número de dados inseridos a AVL se mostra mais competente para realizar a operação de busca. Isso se deve que ao conceito de equilíbro da AVL, diferente da Binaria na qual realizará uma maior quantidade de comparações devido ao seu não balanceamento <p>
 <p> Sobre o tempo de inserção, a medida quevai aumentando a quantidade de números inseridos na AVL, aumentamos também seu tempo em comparação a Binária, no que isso se deve também ao fator de equilíbrio da AVL, que a medida que aumentamos a árvore, teremos que realizar mais rotações para manter sua altura equilibrada <p>
  <p>Portanto, se estamos falando de uma implentação na qual iremos esta inserindo um número elevado de dados nessa árvore, a melhor escolha será a árvore AVL<p>
