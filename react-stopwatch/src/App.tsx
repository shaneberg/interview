import React from 'react';
import './App.css';
function App() {
  const UPDATE_INTERVAL_MS = 50;

  const [totalTime, setTotalTime] = React.useState<number>(0);
  const [running, setRunning] = React.useState<boolean>(false);
  const timerId = React.useRef<NodeJS.Timer>();
  const lastTime = React.useRef<number>(0);

  React.useEffect(() => {
    if (running) {
      lastTime.current = Date.now();

      timerId.current = setInterval(() => {
        const now = Date.now();
        const delta = now - lastTime.current;
        setTotalTime((prev) => prev + delta);
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
    setTotalTime(0);
  };

  return (
    <div className="App">
      <header className="App-header"/>
      <div className="stopwatch">
        <div>{totalTime}</div>
        <button disabled={running} onClick={handleStart}>start</button>
        <button disabled={!running} onClick={handleStop}>stop</button>
        <button onClick={handleReset}>reset</button>
        <div className={`status ${running ? "running" : ""}`}/>
      </div>
    </div>
  );
}

export default App;
