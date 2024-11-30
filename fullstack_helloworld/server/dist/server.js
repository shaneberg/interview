"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const http_1 = __importDefault(require("http"));
const server = http_1.default.createServer((_, response) => {
    response.setHeader("Access-Control-Allow-Origin", "*"); // Allow all origins
    response.setHeader("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
    response.setHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");
    response.writeHead(200, { "Content-Type": "text/plain" });
    setTimeout(() => {
        response.end("Hello, World!");
    }, 5000);
});
server.listen(1701, () => console.log("Server running at http://localhost:1701"));