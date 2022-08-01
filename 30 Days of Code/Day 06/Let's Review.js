
var lineNumber = 0;

function processData(input) {
    //Enter your code here
    const inputLines = input.split(/\n/);
    const totalInputs = inputLines.shift();

    for (let i = 0; i < totalInputs; ++i) {
        let evenChars = '';
        let oddChars = '';
        for (let j = 0; j < inputLines[i].length; ++j) {
            if (j % 2 === 0) {
                evenChars += inputLines[i][j]
            } else {
                oddChars += inputLines[i][j]
            }
        }
        console.log(evenChars + ' ' + oddChars)
    }
}

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
    processData(_input);
});
