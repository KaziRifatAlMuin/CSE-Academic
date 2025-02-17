let text = "";

text += "<h2> My Fruit List </h2>";

const fruits = ["Banana", "Orange", "Apple", "Mango"];
let fLen = fruits.length;

text += "<ul>";
for (let i = 0; i < fLen; i++) {
  text += "<li>" + fruits[i] + "</li>";
}
text += "</ul> <br>";

text += "<h2> Worst Student List </h2>";

const roll = ["2107042", "2107050", "2107032", "2107052", "2107038"];

text += "<ol>";
roll.forEach(myFunction);
text += "</ol>";

function myFunction(value){
    text += "<li>" + value + "</li>";
}

document.write(text); 
