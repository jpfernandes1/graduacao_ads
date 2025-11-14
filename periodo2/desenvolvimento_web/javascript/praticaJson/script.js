/* A API gratuita randomuser.me retorna dados de usuários aleatórios no formato JSON */

const url = 'http://randomuser.me/api/?results=10' // o 10 foi discricionário

// o retorno será uma lista html
async function getUsers(lista){
    const resp = await fetch(url);
    const objeto =  await resp.json();
    let itens = "";

    for(let pessoa of objeto.results){
        itens += `<li>${pessoa.name.first} ${pessoa.name.last} </li>`;
    }
    document.getElementById(lista)
                .innerHTML = itens;
}