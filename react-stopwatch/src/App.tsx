import React from 'react';
import './App.css';

function App() {
  const UPDATE_INTERVAL_MS = 50;

  const [time, setTime] = React.useState<number>(0);
  const [running, setRunning] = React.useState<boolean>(false);
  const timerId = React.useRef<NodeJS.Timer>();
  const lastTime = React.useRef<number>(0);

  React.useEffect(() => {
    if (running) {

      lastTime.current = Date.now();

      timerId.current = setInterval(() => {
        const now = Date.now();
        const delta = now - lastTime.current;
        setTime((prev) => prev + delta);
        lastTime.current = now;
      }, UPDATE_INTERVAL_MS);
    }
  
    return (() => {
      clearInterval(timerId.current);
    });
  }, [running]);


  const handleStart = (): void => {
    setRunning(true);
  };
  const handleStop = (): void => {
    setRunning(false);
  };
  const handleReset = (): void => {
    setTime(0);
  };

  return (
    <div className="App">
      <header className="App-header">
      </header>
      <div>{time}</div>
      <button onClick={handleStart}>start</button>
      <button onClick={handleStop}>stop</button>
      <button onClick={handleReset}>reset</button>
      <div>status: {`${running ? "running" : "stopped"}`}</div>
    </div>
  );
}

export default App;
