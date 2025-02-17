
window.alert("Hello! How's your day?");


console.log("Javascript"); // print something
// variables in js

age = 25; //number
fname = "Kazi Rifat"; //string
price = 120.456;

x = null;
y = undefined;
console.log(fname); 
let sh= "";
sh = sh+"<p> <b>First Name</b> "+fname+"</p>";

document.write(sh);
//boolean type-> true false
isTrue = false;
console.log(isTrue);
age = "two";
//reserved words cannot be variable-> console, swith, case, if,else
//objects

const student = {
    fullName: "Subah", //key:value pairs
    age: 25,
    cgpa: 3.95,
    isPass: true
};

console.log(student.fullName);
console.log(student.age);
console.log(student["fullName"]);
//value update
student["age"]=student["age"]+2;
console.log(student.age);
student.fullName="Mahi";
console.log(student.fullName);
//loops strings
for(let i=1;i<=5;i++) //for while do while
{
    console.log("values of i = ",i);
}

//console.log("values of i = ",i);
//for in and for of
//for of iterates over string and arrays
let str="ThisIsAString";
for(let a of str)
{
    console.log(a);
}
//for in used for objects, objects keys are in iterator
for(let x in student){
    console.log("key=",x,",value=",student[x]); //keys will be returned
}
for(let i=0;i<=100;i+=1)
{   if(i%2==0){ 
        console.log(i);
    }
}

//string length ->str_name.length,str.toUpperCase(), str.toLowerCase(), str.trim()
//template literal
//escape character
//arrays
const fruits = ["Banana", "Orange", "Apple", "Mango"];
let fLen = fruits.length;

let text = "<ul>";
for (let i = 0; i < fLen; i++) {
  text += "<li>" + fruits[i] + "</li>";
}
text += "</ul>";

document.write(text); // Display the list
//push(), pop(), toString()
//function
//dom-> document object model
//events
//classes and object
//fetch api