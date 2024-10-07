import express from "express";
import axios from "axios";
import path from "path";
import fs from "fs";

import { fileURLToPath } from 'url';
const __dirname = path.dirname(fileURLToPath(import.meta.url));

const PORT = 80;
const arduinoUrl = '{ARDUINOIP}:{PORT}';

const app = express();

app.get('/led/:color', async (req, res) => {
    const color = req.params.color;
    if (!['red', 'blue', 'green', 'off'].includes(color)) {
        res.status(500).send(color + ' is not a valid parameter');
        return;
    }

    const requestOptions = {
        method: 'GET',
        url: 'http://' + arduinoUrl + '/' + color
    }

    try {
        let response = await axios(requestOptions);

        if (response.status === 200) {
            res.status(200).send('Success');
        } else {
            res.status(500).send('Didn\'t work');
        }
    } catch (err) {
        console.log(err);
        res.status(500).send('Couldn\'t reach the arduino');
    }


});

app.get('/*', async (req, res) => {
    let url = req.url;
    const options = {root: path.join(__dirname)};
    try{
        if(url === '/'){
            //Send home.html
            await res.sendFile('./web/home.html', options);
        }else{
            if (await fs.existsSync(path.join(__dirname, './web/' + url))) {
                await res.sendFile('./web/' + url, options);
            }else{
                res.status(404).send('Could not find that file');
            }
        }
    }catch(err){
        res.status(404).send('Could not find that file');
    }
});




app.listen(PORT, () => {
    console.log(`Listening on port ${PORT}`);
});