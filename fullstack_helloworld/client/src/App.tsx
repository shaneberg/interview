import React from "react";
import "./App.css";

enum RequestStatus {
  None,
  Requested,
  Processing,
  Completed,
  Error,
}

function App() {
  const [motd, setMotd] = React.useState<string>("...");
  const [requestStatus, setRequestStatus] = React.useState<RequestStatus>(
    RequestStatus.None,
  );

  const requestMotd = () => {
    setRequestStatus(RequestStatus.Requested);
    fetch("http://localhost:1701")
      .then((response: Response) => {
        setRequestStatus(RequestStatus.Processing);
        return response.text();
      })
      .then((parsedResponse) => {
        setRequestStatus(RequestStatus.Completed);
        setMotd(parsedResponse);
      })
      .catch((error) => {
        setRequestStatus(RequestStatus.Error);
        console.log(error);
      });
  };

  React.useEffect(requestMotd, []);

  return (
    <div className="App">
      <header className="App-header"></header>
      <div>{motd}</div>
      <div>{requestStatus}</div>
    </div>
  );
}

export default App;
