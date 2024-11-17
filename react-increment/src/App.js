import './App.css';

import React, {useState} from 'react';

function App() {

    const [count, setCount] = useState(0);
    const increment = () => setCount((prevCount) => prevCount + 1);
    const decrement = () => setCount((prevCount) => prevCount - 1);

    return (
        <div className="App">
            <header className="App-header">
                <h1>{count}</h1>
                <button onClick={increment}>Increment</button>
                <button onClick={decrement}>Decrement</button>
            </header>
        </div>
  );
}

export default App;
