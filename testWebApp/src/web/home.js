window.onload = function (e) {
    console.log('loaded');
}


function onButtonPress(value) {
    switch (value) {
        case "red":
            callApi('/led/red');
            break;
        case "green":
            callApi('/led/green');
            break;
        case "blue":
            callApi('/led/blue');
            break;
        case "off":
            callApi('/led/off');
            break;
    }
}



/**
 * @returns Obj with 2 fields: status (integer) and response (object if success or string with error message)
 * 
 * @param {string} uri Ex: '/api/nowPlaying
 * @param {*} queryParams, object with key value pairs
 */
async function callApi(uri, queryParams, method) {
    let auth_token = sessionStorage.getItem('auth-token');

    let queryString = '';
    for (const query in queryParams) {
        if (queryString === '') {
            queryString += '?' + query + '=' + queryParams[query];
        } else {
            queryString += '&' + query + '=' + queryParams[query];
        }
    }

    const headers = {
        authorization: auth_token
    }
    const response = await fetch(uri + queryString, {
        method: method ? method : 'GET',
        headers: headers
    });

    if (response.status !== 200) {
        //Error
        return {
            status: response.status,
            data: response.body
        }
    }
    const data = await response.json();
    return {
        status: 200,
        data: data
    };
}
