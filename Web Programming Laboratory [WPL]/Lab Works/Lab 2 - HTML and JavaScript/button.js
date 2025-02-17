function mul() {
    num1 = document.getElementById("n1").value;
    num2 = document.getElementById("n2").value;
    document.getElementById("result").innerHTML = num1 * num2;
}

function div() {
    num1 = document.getElementById("n1").value;
    num2 = document.getElementById("n2").value;
    if(num2 == 0) document.getElementById("result").innerHTML = "Devide by Zero";
    document.getElementById("result").innerHTML = num1 / num2;
}