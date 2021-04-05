#!/usr/bin/node
// print all characters of a Star Wars movie
const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}`;
const getPerson = (charEndpoint) => {
  request(charEndpoint, function (error, response, body) {
    if (error) throw error;
    console.log(JSON.parse(body).name);
  });
};
request(url, function (error, response, body) {
  if (error) throw error;
  JSON.parse(body).characters.forEach(character => getPerson(character));
});