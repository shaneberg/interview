import './App.css'

import {useState} from 'react';

const App = () => {
    const [word, setWord] = useState('');

    const WordleInput = () => {

        const [input, setInput] = useState('');
        const handleInput = (text) => {
            return setInput(text);
        };

        return (
            <div>
                <input name="wordle-input" type="text" value={input} onChange={(e) => handleInput(e.target.value)}/>
            </div>
        );

    };

    const WordleTile = ({letter}) => {
        return (
            <div className="wordle-tile">{letter}</div>
        );
    };

    const WordleRow = () => {
        const letters = ['a', 'b', 'c', 'd', 'e'];
        return (
            <div className="wordle-row">
                {letters.map((letter, iter) => { return (<WordleTile key={iter} letter={letter} />); })}
            </div>
        );
    };

    return (
        <div className="App">
            <header className="App-header">
                <p> React Wordle </p>
            </header>
            <div className="wordle-game">
                <WordleRow />
                <WordleRow />
                <WordleRow />
                <WordleRow />
                <WordleRow />
                <WordleInput />
            </div>
        </div>
    );
}

export default App;
