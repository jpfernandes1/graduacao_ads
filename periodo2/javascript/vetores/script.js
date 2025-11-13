// Criação do vetor vazio
let valores = [];

// Criando função que irá gerar os pares ordenados
const addValor = (x) => {
    // Sempre que fizer o push, irá criar o par (x,y), onde x será o índice + 1 (já que o inicial é zero e queremos contar a partir de 1, sendo incrementado a cada chamada) 
    // e y será o valor inserido pelo usuário
    valores.push([valores.length+1,x]);
}

// Função para reiniciar o vetor;
const limpar = () => {
    valores = [];
}

const media = () => {
    let soma = 0;
    // for/of para pegar diretamente os valores
    for (x of valores){
        // selecionar somente os y do par ordenado
        soma += x[1];
        return soma / valores.length;
    }
}

// Função para desenhar o gráfico
const drawBasic = () => {
    var data = new google.visualization.DataTable();
    data.addColumn('number', 'Pos');
    data.addColumn('number', 'X');
    data.addRows(valores);
    var options = {hAxis:{title: 'Posicao'}, vAxis: {title: 'Valor de X'}};

    var chart = new google.visualization
                        .LineChart(document.getElementById('chart_div'));

    chart.draw(data, options);
}