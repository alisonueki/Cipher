// server.js
const express = require('express');
const bodyParser = require('body-parser');
const { spawn } = require('child_process');

const app = express();
const port = 3000;

app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static('public'));

app.post('/encrypt', (req, res) => {
  const message = req.body.message;
  
  const cipherProcess = spawn('./a.out'); // Assuming the compiled C++ executable is named 'a.out'

  cipherProcess.stdin.write('1\n'); // Encrypt option
  cipherProcess.stdin.write(`${message}\n`);
  cipherProcess.stdin.end();

  let encryptedResult = '';
  cipherProcess.stdout.on('data', (data) => {
    encryptedResult += data.toString();
  });

  cipherProcess.on('close', () => {
    res.send(encryptedResult);
  });
});

app.post('/decrypt', (req, res) => {
  const encryptedMessage = req.body.encryptedMessage;

  const cipherProcess = spawn('./a.out'); // Assuming the compiled C++ executable is named 'a.out'

  cipherProcess.stdin.write('2\n'); // Decrypt option
  cipherProcess.stdin.write(`${encryptedMessage}\n`);
  cipherProcess.stdin.end();

  let decryptedResult = '';
  cipherProcess.stdout.on('data', (data) => {
    decryptedResult += data.toString();
  });

  cipherProcess.on('close', () => {
    res.send(decryptedResult);
  });
});

app.listen(port, () => {
  console.log(`Server running on http://localhost:${port}`);
});
