console.log("main.js");

function add(){
    console.log("js.add()");
    var result = Module.ccall('add', 'number', ['number','number'], [1,2]);
    console.log("result:", result);
    //document.getElementById('results').innerHTML = result;
}

function evalString(){
    console.log("evalString()");
    var inputStr = document.getElementById("repl-input").value;
    console.log(inputStr);
    var error = Module.ccall('eval_string', 'int', ['string'], [inputStr]);
    console.log("  returned:", error);
}

function showResults(msg){
    console.log("showResults() msg:", msg);
    document.getElementById('results').innerHTML = msg;
}
