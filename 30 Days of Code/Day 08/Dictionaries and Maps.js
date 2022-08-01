function processData(input) {
    inputData = input.split('\n');
    const inputLength = inputData.shift();
    let contactMap = [];
    for (let i = 0; i < inputLength; ++i) {
        [name, phone] = inputData[i].split(' ');
        contactMap[name] = phone;
    }

    for (let i = inputLength; i < inputData.length; ++i) {
        const q = inputData[i];
        const phone = contactMap[q];
        if (!phone) {
            console.log('Not found');
            continue;
        }
        console.log(`${q}=${phone}`);
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
