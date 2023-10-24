const express = require('express');
const arest = require('arest');
const path = require('path');

const app = express();
const port = 3000;

arest.addDevice('http','your_esp_ip');

app.use(express.static(path.join(__dirname, 'public')));
app.use(arest.handle);

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname + '/public/index.html'));
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});
