import http from "http";

const server = http.createServer(
  (_: http.IncomingMessage, response: http.ServerResponse) => {
    response.setHeader("Access-Control-Allow-Origin", "*"); // Allow all origins
    response.setHeader(
      "Access-Control-Allow-Methods",
      "GET, POST, PUT, DELETE, OPTIONS",
    );
    response.setHeader(
      "Access-Control-Allow-Headers",
      "Content-Type, Authorization",
    );

    response.writeHead(200, { "Content-Type": "text/plain" });
    setTimeout(() => {
      response.end("Hello, World!");
    }, 5000);
  },
);

server.listen(1701, () =>
  console.log("Server running at http://localhost:1701"),
);
