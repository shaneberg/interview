import './App.css';

import {useState} from 'react';

function App() {

    const TodoItem = ({item}) => {

        const handleClick = () => {
            setComplete(item.id, !item.completed);
        };

        return(
            <div className={`todo-item ${item.completed ? 'completed' : ''}`}>
                <input className='todo-checkbox' type="checkbox" checked={item.completed} onChange={handleClick} />
                <div>{item.text}</div>
            </div>
        );
    };

    const [list, setList] = useState([]);
    const [todo, setTodo] = useState('');
    const addTodo = () => {
        setList((prevList) => [...prevList, {completed: false, text: todo, id: prevList.length + 1}]);
        setTodo('');
    };

    const setComplete = (id, complete) => setList((prevList) => prevList.map((item) => {
        return { ...item, completed: id === item.id ? complete : item.completed };
    }));

    return (
        <div className="App">
            <header className="App-header" />
            <div className="todo-container">
                <div className="todo-list">
                    <h3>TODO</h3>
                    {list.map((item, iter) => (<TodoItem key={iter} item={item} />))}
                    <input
                        value={todo}
                        onChange={(e) => setTodo(e.target.value)}
                        onKeyDown={(e) => { if (e.key === "Enter" && e.target.value) { addTodo() }}}
                    />
                    <button onClick={addTodo}>Add</button>
                </div>
            </div>
        </div>
    );
}

export default App;
